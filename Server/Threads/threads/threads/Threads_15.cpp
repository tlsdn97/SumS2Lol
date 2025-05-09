#include "framework.h"

class TestJop
{
	USE_LOCK

public:
	
	int TestRead()
	{
		READ_LOCK
			if (q.empty() == false)
				return q.front();

		return -1;
	}

	void TestPush()
	{
		WRITE_LOCK

			q.push(rand() % 100);
	}
	
	void TestPop()
	{
		WRITE_LOCK

			if (q.empty() == false)
				q.pop();
	}


private:
	queue<int> q;
};

TestJop Gjob;

void ThreadRead()
{
	while (true)
	{
		int num = Gjob.TestRead();
		cout << num << endl;
	}
}

void ThreadWrite()
{
	while (true)
	{
		Gjob.TestPush();
		Gjob.TestPop();
	}
}

int main()
{
	ThreadManager::Create();

	ThreadManager::Delete();

	return 0;
}