#pragma once

// 1. 공유 변수를 읽거나 수정
// Player; 
// a, b, c threads
// a 쓰레드 R / b쓰레드 R / c 쓰레드 R

// => spin Lock 같은 경우 c 쓰레드는 a,b 가 다 읽기 전까지 읽을 수 없다

// 읽는 것만 할거면 다들 동시에 봐도 상관없지 않을까?

// [wwwwww] [wwwwww] [rrrrrr] [rrrrrrrr] => 32개의 비트
// 1. 여러쓰레드가 'Read' 만 할경우 : readlock 몇 번을 걸었는지 기입
// 2.
// 3.
// .


// ReadLock  정책
// 1. Read는 상호베타적일 필요없이 고유 count만 올리겠다.
// 2. Write는 무조건 상호베타적이여야한다.
// 3. Write중에는 다른 쓰레드에서 Write를 시도할 수 없다.
// 4. Read중에는 다른 쓰레드에서 Write를 시도할 수 없다.
// => 내 Thread에서 Write하고 Read,Write하는 것을 가능하다.
// => 내 Thread에서 Read하고 Write하는 것 불가능.

class RWLock
{
	enum : uint32
	{
		EMPTY_FLAG = 0x0000'0000,
		MAX_SPIN_COUNT = 5000,
		WRITE_THREAD_MASK = 0x0000'FFF,
		READ_COUNT_MASK = 0x0000'FFFF,
		ACQUIRE_TIMEOUT_TICK = 10000
	};

public:

	void WriteLcok(const char* name);
	void ReadLock(const char* name);
	void WriteUnLcok(const char* name);
	void ReadUnLock(const char* name);
	

private:

	Atomic<uint32> _lockFlag = 0;

	uint16 _writeCount = 0;
};

class ReadLockGuard
{
public:
	ReadLockGuard(RWLock& lock, const char* name) : _lock(lock), _name(name)
	{
		_lock.ReadLock(_name);
	}
	~ReadLockGuard()
	{
		_lock.ReadUnLock(_name);
	}

private:
	const char* _name;
	RWLock& _lock;
};

class WriteLockGuard
{
public:
	WriteLockGuard(RWLock& lock, const char* name) : _lock(lock), _name(name)
	{
		_lock.WriteLcok(_name);
	}
	~WriteLockGuard()
	{
		_lock.WriteUnLcok(_name);
	}

private:
	const char* _name;
	RWLock& _lock;
};
