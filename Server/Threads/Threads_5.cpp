#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>

using namespace std;

// SpinLook =>  mutex
// Lock Ǯ�� ������ ������ ���� �ݺ� ���
// 
// Sleep Lock
// lock�� ��������� Sleep ��Ű��, �ٽ� �ǵ��ƿͼ� Ȯ�� �� Sleep or Excute ����
// Sleep : �ü�翡�� thread�� ����.

// Sleep Lock�� ����
// - �ڰ� �Ͼ�� ���� �� �̹� �ٸ� �����尡 �����ؼ� �־��� ��� ���� �ð����� ���� ���� ���� �ִ�.


// Spin Lock�� ����
// - thread�� ���� �ʰ� ��� ���� ����

// Context swiching  : 


int sum = 0;
std::mutex myMutex;

class SpinLock
{
public:
	void lock()
	{
		// ���ϰ� ���� �����ϴ� ������ �ѹ���.
		// CAS : Compare And Swap
		
		bool expected = false;
		bool desired = true;

		// Compare_exchange_strong
		// if(_locked = expected)
		// {
		//    expected = _locked;
		//	  _locked = desired
		//		return true;
		// }
		// eles
		// {
		//		expected = _locked;
		//		return false;
		// }


		while (_locked.compare_exchange_strong(expected, desired) == false)
		// 1. ���� _locked �� false ���� => 
		// _lock�� desired(true) �ٲ�� true ����
		{
			expected = false;

			this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

	}

	void unlock()
	{
		_locked.store(false);
	}
	
private:
	atomic<bool> _locked = false;
};

SpinLock _myLock;


void Add()
{
	for (int i = 0; i < 10000; i++)
	{
		lock_guard<SpinLock> lg(_myLock);
		sum++;
	}
}

void Sum()
{
	for (int i = 0; i < 10000; i++)
	{
		lock_guard<SpinLock> lg(_myLock);
		sum--;
	}
}

//  �ڵ� ����ȭ��?
int main()
{

	std::thread t1(Add);
	std::thread t2(Sum);

	t1.join();
	t2.join();

	cout << sum << endl;

	return 0;
}