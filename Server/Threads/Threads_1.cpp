#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <thread>

using namespace std;

// 1. 프로세스 vs 쓰레드 차이점 조사
// 2. CPU 코어 와 쓰레드의 상관관계 조사

// 식당
// 1. 손님 응대 < 1
// 2. 음식 조리 
// 3. 서빙
// 4. 설거지 < 2
// 5. 계산

// thread : 알바, PAWN 로 비유

void HelloThread()
{
	cout << "Hello Thread" << endl;
}

int sum = 0;

void AddSum()
{
	for (int i = 0; i < 10000; i++)
		sum++;
}

void SubSum()
{
	for (int i = 0; i < 10000; i++)
		sum--;
}

int main()
{
	// vector<std::thread> threads;
	// for (int i = 0; i < 5; i++)
	// 	threads.push_back(std::thread(AddSum));
	// 
	// for (int i = 0; i < 5; i++)
	// 	threads.push_back(std::thread(SubSum));
	// 
	// for (auto& t : threads)
	// 	t.join();

	 std::thread t1(AddSum);
	 std::thread t2(SubSum);
	
	t1.join(); 
	t2.join();

	cout << sum << endl;

	return 0;
}