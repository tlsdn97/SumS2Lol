#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <atomic>
#include <mutex>


using namespace std;

vector<int> v;
std::mutex m; // ¿⁄π∞ºË

// lock
// mutex :: mutual exclusion

// RAII : Resource acquisition is initialization
// ∏Æº“Ω∫ »πµÊ¿∫ √ ±‚»≠, ∏Æº“Ω∫ µÂ∂¯¿∫ º“∏Í


 template<typename T> 
class LockGuard
{
public:
	LockGuard(T* mutex) : _mutex(mutex) { _mutex->lock(); } // mutex »πµÊ
	~LockGuard() { _mutex->unlock(); }	

private:

	T* _mutex;

};

void Push(int num)
{
	LockGuard<std::mutex> lg(&m);

	v.push_back(num);
}

void Pop()
{
	v.pop_back();
}

int main()
{

	std::thread t1([]() -> void
	{
			for (int i = 0; i < 1000; i++)
			{
				Push(i);
			}

	});

	std::thread t2([]() -> void
	{
			for (int i = 0; i < 1000; i++)
			{
				Push(i);
			}

	});
	
	t1.join();
	t2.join();

	cout << v.size() << endl;
 
	return 0;
}