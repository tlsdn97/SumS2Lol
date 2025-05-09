#include "framework.h"
#include "RWLock.h"


void RWLock::WriteLcok()
{
	uint32 lockThreadID = (_lockFlag & WRITE_THREAD_MASK) >> 16;

	if (LThreadID == lockThreadID)
	{
		_writeCount++;
		return;
	}

	uint64 beginTick = ::GetTickCount64();

	uint32 deisired = LThreadID << 16;
	while (true)
	{
		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			uint32 expected = EMPTY_FLAG;


			if (_lockFlag.compare_exchange_strong(expected, deisired))
			{
				_writeCount++;
				return;
			}
		}

		if (::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT_TICK)
		{
			int32* temp = (int32*)0xDEADBEFF;
			*temp = 5;
		}

		this_thread::yield();
	}
}

// [wwwwww] [wwwwww] [rrrrrr] [rrrrrrrr]
// [wwwwww] [wwwwww]

void RWLock::ReadLock()
{
	// ThreadID ����
	uint32 lockThreadID = (_lockFlag & WRITE_THREAD_MASK) >> 16;

	// ���� Thread �� WirteLock ��Ҿ���. => ���
	if (LThreadID == lockThreadID)
	{
		_lockFlag.fetch_add(1);
		return;
	}

	// writelock �� �ְ� �ٸ� ��.... ����� => WriteLFlag�� �� �ƴϿ���. => spinlock
	// writrelock�� �Ȱɷ��־���.. ��� => 
	int64 beginTick = ::GetTickCount64();
	while (true)
	{
		for (uint64 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			// lockThreadID�� ���������� �ѹ��� �ٲ�ġ�� ������Ѵ�.
			uint32 expected = (_lockFlag.load() & READ_COUNT_MASK); // => WriteFlag�� 0�� ������ ����
			uint32 desited = expected + 1; //wirteflagrk 0�̸� Readcount�� 1 �÷��ִ� ���� ���
			if (_lockFlag.compare_exchange_strong(expected, desited))
			{
				return; // ��� 
			}

			// ���� �ϸ鼭 �ð��� ���� �� ACQUIRE_TIMEOUT_TICK ���� Ŀ���� CRASH
			if (::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT_TICK)
			{
				// TODO : CRASH
				int32* temp = (int32*)0xDEADBEFF;
				*temp = 5;
			}
		}
	}
}

void RWLock::WriteUnLcok()
{
	if ((_lockFlag.load() & READ_COUNT_MASK) != 0)
	{
		int32* temp = (int32*)0xDEADBEFF;
		*temp = 5; 
	}

	int32 lockCount = --_writeCount;
	if (lockCount == 0)
	{
		_lockFlag.store(EMPTY_FLAG);
	}
}

void RWLock::ReadUnLock()
{
	if ((_lockFlag.fetch_add(1) & READ_COUNT_MASK) == 0)
	{
		// TODO
	}
}
