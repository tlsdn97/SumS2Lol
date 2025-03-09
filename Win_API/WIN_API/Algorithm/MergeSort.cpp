#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// ������ ����
// �ӽù迭�� �����.

// ����, ����
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// ó���� ������ ���� ���� �߰� �ɰ��� ���¿��� ����
	// [30] , [55]
	// left = 1
	// right = 2
	// mid = 1

	int leftIndex = left;
	int rightIndex = mid + 1;
	vector<int> temp;

	// [30]         [55]
	// leftIndex,  rightIndex
	while (true)
	{
		if (leftIndex > mid || rightIndex > right)
			break;

		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}

		// [30]         [55]
		//            rightIndex
		//             leftIndex
		else
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	// ... ���� Ȥ�� �����ʿ� �ִ� �迭���� temp �迭�� ������ ��Ȳ

	// right���� �����־���...
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	// left���� �����־���.
	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	// temp�� ���ĵ� �迭�� ����
	// => temp�� v�� ������ ����
	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

void MergeSort(vector<int>& v, int left, int right)
{
	// �������� : ���� �߰� �ɰ��� ��
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	// Divide
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	// Conquer And Combine
	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v = { 55, 30, 15, 100, 1, 5, 30 };
	MergeSort(v, 0, v.size() - 1);

	std::sort(v.begin(), v.end()); // N x logN
	// ���� ����

	std::partial_sort(v.begin(), v.begin() + 3, v.end()); // N x logM => �տ� 3���� �ִ밪���� ����
	
	std::stable_sort(v.begin(), v.end()); // N x logN
	// ������ ����(���� ���� ��� �տ��ִ� ���� ������ �տ� �ִ�.)
	// ... �ӽù迭 �����.

	return 0;
}