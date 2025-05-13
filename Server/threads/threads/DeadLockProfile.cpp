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

	// .... 미리 lock이 있었다.
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

	_discoveredOrder = vector<int32>(lockCount, -1); // 순서 기입
	_discoveredCount = 0;
	_finished = vector<bool>(lockCount, false);
	_parent = vector<int32>(lockCount, -1); //부모 기입

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

	// here에서 인접한 정점이 없다.
	// 첫번째 lock이자 마지막 lock
	if (findIt == _lockHistory.end());
	{
		_finished[here] = true;
		return;
	}

	set<int32>& thereSet = findIt->second;
	for (int32 there : thereSet)
	{
		// 인접해있나? {}

		// 자기자신인가? {}
		
		// 방문이 되어있나?
		if (_discoveredOrder[there] == -1)
		{
			_parent[there] = here;
			DFS(there);
			continue;
		}


		// here 방문체크 , there는 이미 방문
		// 순방향 간선
		if (_discoveredOrder[here] < _discoveredOrder[there])
			continue;

		// 순방향 간선이 아니고, there가 here보다 작다? => there는 here의 선조 => 역방향간선
		// there 의 DFS 가 끝나지 않았다.
		if (_finished[there] == false)
		{
			//  백트래킹해서 어디에서 어디부터까지  DEADLOCK 경로 출력
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
