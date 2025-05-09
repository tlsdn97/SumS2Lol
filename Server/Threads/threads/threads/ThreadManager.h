#pragma once

/// <summary>
/// Thread를 생성해서 담아놓고, 실행할 함수를 계속 관리하는 Manager
/// </summary>

class ThreadManager
{
private:
	ThreadManager();
	~ThreadManager();

public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new ThreadManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

	static ThreadManager* Instance()
	{
		return _instance;
	}

	void Launch(function<void(void)> callback); // Callable 객체(함수 포인터, 함수 객체)
	void Join();

	static void InitTLS();
	static void DestroyTLS();

private:
	static ThreadManager* _instance;
	static Atomic<int> SThreadID;

	TArray<thread> _threads;
	Mutex _lock;
};

