#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <thread>

using namespace std;

// 1. ���μ��� vs ������ ������ ����
// 2. CPU �ھ� �� �������� ������� ����

// �Ĵ�
// 1. �մ� ���� < 1
// 2. ���� ���� 
// 3. ����
// 4. ������ < 2
// 5. ���

// thread : �˹�, PAWN �� ����

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