#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>

using namespace std;

// SpinLook =>  mutex
// Lock 풀릴 때까지 쓰레드 무한 반복 대기
// 
// Sleep Lock
// lock의 잠겨있으면 Sleep 지키고, 다시 되돌아와서 확인 후 Sleep or Excute 결정
// Sleep : 운영체재에서 thread를 재운다.

// Sleep Lock의 단점
// - 자고 일어나서 왔을 때 이미 다른 쓰레드가 점유해서 최악의 경우 오랜 시간동안 일을 못할 수도 있다.


// Spin Lock의 단점
// - thread가 쉬지 않고 계속 무한 루프

// Context swiching  : 


int sum = 0;
std::mutex myMutex;

class SpinLock
{
public:
	void lock()
	{
		// 비교하고 값을 대입하는 과정이 한번에.
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
		// 1. 만약 _locked 가 false 였다 => 
		// _lock은 desired(true) 바뀌고 true 리턴
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

//  코드 최적화란?
int main()
{

	std::thread t1(Add);
	std::thread t2(Sum);

	t1.join();
	t2.join();

	cout << sum << endl;

	return 0;
}