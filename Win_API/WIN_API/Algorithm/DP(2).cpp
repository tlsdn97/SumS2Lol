#include <iostream>
#include <vector>

using namespace std;

// ����ϱ�
// ��ȭ�� �ϴµ�, +1, +2, +3
// n���� �ϰ� �ʹ�.
// => �� �� ���� �� �ִ� ����� ��
// 0 < n < 3000
// 

// ex) 3���� �ϰ� �ʹ�.
// 1 1 1
// 1 2
// 2 1
// 3
// 4

// ex) 4��
// DP[3] + DP[1]
// DP[2] + DP[2]
// DP[1] + DP[3]

vector<int> cache = vector<int>(3001, -1);
int Enchant(int n)
{
	// �����
	if (n == 0 || n == 1)
		return 1;
	if (n < 0)
		return 0;

	int& ref = cache[n];
	if (ref != -1)
		return ref;

	return ref = Enchant(n - 1) + Enchant(n - 2) + Enchant(n - 3);
}

int main()
{

	cout << Enchant(3) << endl; // 4

	return 0;
}