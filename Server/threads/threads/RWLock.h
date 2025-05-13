#pragma once

// 1. ���� ������ �аų� ����
// Player; 
// a, b, c threads
// a ������ R / b������ R / c ������ R

// => spin Lock ���� ��� c ������� a,b �� �� �б� ������ ���� �� ����

// �д� �͸� �ҰŸ� �ٵ� ���ÿ� ���� ������� ������?

// [wwwwww] [wwwwww] [rrrrrr] [rrrrrrrr] => 32���� ��Ʈ
// 1. ���������尡 'Read' �� �Ұ�� : readlock �� ���� �ɾ����� ����
// 2.
// 3.
// .


// ReadLock  ��å
// 1. Read�� ��ȣ��Ÿ���� �ʿ���� ���� count�� �ø��ڴ�.
// 2. Write�� ������ ��ȣ��Ÿ���̿����Ѵ�.
// 3. Write�߿��� �ٸ� �����忡�� Write�� �õ��� �� ����.
// 4. Read�߿��� �ٸ� �����忡�� Write�� �õ��� �� ����.
// => �� Thread���� Write�ϰ� Read,Write�ϴ� ���� �����ϴ�.
// => �� Thread���� Read�ϰ� Write�ϴ� �� �Ұ���.

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
