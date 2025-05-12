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
	// ThreadID 추출
	uint32 lockThreadID = (_lockFlag & WRITE_THREAD_MASK) >> 16;

	// 같은 Thread 가 WirteLock 잡았었다. => 통과
	if (LThreadID == lockThreadID)
	{
		_lockFlag.fetch_add(1);
		return;
	}

	// writelock 건 애가 다른 애.... 불통과 => WriteLFlag가 이 아니였다. => spinlock
	// writrelock이 안걸려있었다.. 통과 => 
	int64 beginTick = ::GetTickCount64();
	while (true)
	{
		for (uint64 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			// lockThreadID가 원차적으로 한번에 바꿔치기 해줘야한다.
			uint32 expected = (_lockFlag.load() & READ_COUNT_MASK); // => WriteFlag가 0일 것으로 예상
			uint32 desited = expected + 1; //wirteflagrk 0이면 Readcount를 1 올려주는 것을 희망
			if (_lockFlag.compare_exchange_strong(expected, desited))
			{
				return; // 통과 
			}

			// 스핀 하면서 시간을 잿을 때 ACQUIRE_TIMEOUT_TICK 보다 커지면 CRASH
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
