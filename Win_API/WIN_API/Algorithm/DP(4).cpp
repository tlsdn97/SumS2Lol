#include <iostream>
#include <vector>

using namespace std;

// LIS (�κ� ���� ����)�� �ִ���
// { 10 , 5 , 6, 7, 9 } ��������X
// �κ� ���� ����
// {7,9}, {6,9} ... {5 ,7 ,9}
// 
// {1, 10, 11, 15, 30} ��������

// { 10 , 5 , 6, 7, 9 }
// 5 + 6 + 7 + 9

// {1, 10, 11, 15, 30}
// 1 + 10 + 11 + 15 + 30

// {10,7,5,3}
// 10

// {15, 30, 10, 17, 50} = 95

// {5,4,3,2,1,} = 5

// {1,2,3,4,5} = 15

int cache[1001];

int LIS(int n, vector<int>& v) // Longest Increasing Sequence�� �ִ��� ���ϱ�
{
	// ��������
	if (n == v.size() - 1)
		return v[n];

	// �޸������̼�
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// ���ϱ�
	ref = v[n];
	for (int next = n + 1; next < v.size(); next++)
	{
		if (v[n] <= v[next])
			ref = std::max(ref, LIS(next, v) + v[n]);
	}

	return ref;
}

int main()
{
	vector<int> v = { 5,6,7,1,2,3,4 };

	int anwser = 0;

	for (int i = 0; i < 1001; i++)
	{
		cache[i] = -1;
	}

	for (int i = 0; i < v.size(); i++)
	{
		anwser = std::max(anwser,LIS(i, v));
	}

	cout << anwser << endl;

	return 0;
}