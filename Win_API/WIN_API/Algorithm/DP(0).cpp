#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// DP : Dynamic Programming ������ȹ��
// ������

// => ����ȭ

// 1. ��ȭ�� ã�� : ���� �κ� ����
//  : ������ ���� ���� ���� ���� ���� �� ���δ�.
// => ���� ���� ���� �̸� �������.(�޸������̼�)
// 
// 2. �������� ã��
// 3. ĳ������


// �Ǻ���ġ ����
// f(0) = 1
// f(1) = 1
// f(n) = f(n-1) + f(n-2) ...��ȭ��

// f(2) ... 2
// f(3) ... 3
// f(4) ... 5
// f(5) ... 8
// f(10) ...
int countA = 0;
int Fibonacci(int n)
{
	if (n == 0 || n == 1)
		return 1;

	if (n == 2)
		countA++;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// n... 1000����
vector<int> cache = vector<int>(1001, -1);
int FibonacciDP(int n)
{
	// ��������
	if (n == 0 || n == 1)
		return 1;
	if (n == 2)
	{
		countA++;
	}

	// �޸������̼�
	int& ref = cache[n];
	if (ref != -1)
	{
		return ref;
	}

	// ���ϱ�
	return ref = FibonacciDP(n - 1) + FibonacciDP(n - 2);
}

int main()
{
	__int64 start = GetTickCount64();

	cout << FibonacciDP(70) << endl;

	cout << "f(2)�� ȣ��� Ƚ��" << countA << endl;
	__int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;

	return 0;
}