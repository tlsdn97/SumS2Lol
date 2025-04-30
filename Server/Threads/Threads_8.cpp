#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <future>	

using namespace std;

__int64 Caculate()
{
	__int64 sum = 0;

	for (int i = 0; i < 100'0000; i++)
	{
		sum += i;
	}

	return sum;
}

void PromiseWorker(std::promise<string>&& promise)
{
	promise.set_value("Set Massage");
}

void TaskWorker(std::packaged_task<__int64()>&& task)
{
	task();
}

int main()
{
	//future
	{
		// std::launch::deferred : ������Ű�ż� ���߿� ����
		// std::launch::async : �����带 �ϳ� �ļ� ����

		// �񵿱� ������� future���� �� ���� ����� ���߿� ��ȯ�޴� ��.
		std::future<__int64> f = std::async(std::launch::async, Caculate);


		// TODO ... => f�� �������� ������ �ʴ��� ����  �� ������� ����
		int temp = 0;

		__int64 sum = f.get();

		cout << sum << endl;
	}

	// promise : ��������� �����Ѵ�.(��Ƽ������ ��������)
	{
		// �̷����� ���� ���� ���� ����
		std::promise<string> promise;
		std::future<string> future = promise.get_future(); // future���� ��ȯ�ϰڴ� ��� ���

		std::thread t(PromiseWorker, std::ref(promise));

		std::future_status status = future.wait_for(10ms); //0.01�� ���� ����ϸ鼭 future�� ���� Ȯ��
		if (status == future_status::ready)
		{
			// future�� ������ �� �Ǿ��ִ�. => ��� ���� ����
			string value = future.get();
			cout << value << endl;
		}

		t.join();
	}

	// packaged_task : �ϰ�(function)�� ���� �Ѱ��ִ� ���
	{
		// task�� �̷��� ����Ű�� �� ��ȯ���� f_result�� �����ְڴ�.
		std::packaged_task<__int64()> task(Caculate);
		std::future<__int64> f_result = task.get_future();

		std::thread t(TaskWorker, std::ref(task));

		__int64 sum = f_result.get();

		cout << sum << endl;

		t.join();
	}

	// Cacluate  �ϴµ� Event��� Lock, SpinLock, SleepLock�� �ɰ� ��Ƽ�����忡�� �۾��ϴ� ȯ���� �ּ�ȭ
	// ���� �۾����� �ϴµ� �񵿱����� �ʿ��� ��� => future
	// ����) C# await

	return 0;
}