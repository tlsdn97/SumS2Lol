#include "framework.h"
#include "DeadLockProfile.h"

void DeadLockProfile::PushLock(const char* name)
{
	LockGuard lg(_lock);

	int32 lockId = 0;

	auto findIt = _nameToID.find(name);
	if (findIt == _nameToID.end())
	{
		lockId = static_cast<int32>(_nameToID.size());
		_nameToID[name] = lockId;
		_idToName[lockId] = name;
	}
	else
	{
		lockId = findIt->second;
	}

	// .... �̸� lock�� �־���.
	if (_lockStack.empty() == false)
	{
		const int32 prevID = _lockStack.top();
		if (lockId != prevID)
		{
			set<int32>& history = _lockHistory[prevID];
			if (history.find(lockId) == history.end())
			{
				history.insert(lockId);
				CheckCycle();
			}
		}
	}

	_lockStack.push(lockId);
}

void DeadLockProfile::PopLock(const char* name)
{
	LockGuard lg(_lock);

	if (_lockStack.empty())
		CRASH("MULTIPLE POP");

	int32 lockID = _nameToID[name];
	if (_lockStack.top() != lockID)
		CRASH("UNVALID POP");


	_lockStack.pop();
}

void DeadLockProfile::CheckCycle()
{
	const int32 lockCount = static_cast<int32>(_nameToID.size());

	_discoveredOrder = vector<int32>(lockCount, -1); // ���� ����
	_discoveredCount = 0;
	_finished = vector<bool>(lockCount, false);
	_parent = vector<int32>(lockCount, -1); //�θ� ����

	for (int32 lockID = 0; lockID < lockCount; lockID++)
	{
		DFS(lockID);
	}

	_discoveredOrder.clear();
	_finished.clear();
	_parent.clear();
}

void DeadLockProfile::DFS(int32 here)
{
	if (_discoveredOrder[here] != -1)
		return;

	_discoveredOrder[here] = _discoveredCount++;

	auto findIt = _lockHistory.find(here);

	// here���� ������ ������ ����.
	// ù��° lock���� ������ lock
	if (findIt == _lockHistory.end());
	{
		_finished[here] = true;
		return;
	}

	set<int32>& thereSet = findIt->second;
	for (int32 there : thereSet)
	{
		// �������ֳ�? {}

		// �ڱ��ڽ��ΰ�? {}
		
		// �湮�� �Ǿ��ֳ�?
		if (_discoveredOrder[there] == -1)
		{
			_parent[there] = here;
			DFS(there);
			continue;
		}


		// here �湮üũ , there�� �̹� �湮
		// ������ ����
		if (_discoveredOrder[here] < _discoveredOrder[there])
			continue;

		// ������ ������ �ƴϰ�, there�� here���� �۴�? => there�� here�� ���� => �����Ⱓ��
		// there �� DFS �� ������ �ʾҴ�.
		if (_finished[there] == false)
		{
			//  ��Ʈ��ŷ�ؼ� ��𿡼� �����ͱ���  DEADLOCK ��� ���
			cout << _idToName[here] << "->" << _idToName[there] << endl;

			int32 now = here;
			while (true);
			{
				cout << _idToName[_parent[now]] << "->" << _idToName[now] << endl;
				now = _parent[now];
				if (now == there)
					break;
			}

			CRASH("DEADLOCK_DETECTED");
		}

	}

	_finished[here] = true;
}
