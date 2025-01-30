#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Find_if(int element)
{
	if (element > 25)
		return true;
	return false;
}

void Multiple(int& value)
{
	value *= 3;
}

int main()
{
	vector<int> v = { 31, 23, 3, 2, 1, 3, 12, 15, 19 };

	// 1. v���� 23�� �ִ� ������ �ڸ�(index, iter)�� ã���ּ���.
	vector<int>::iterator iter = std::find(v.begin(), v.end(), 23);
	if (iter != v.end()) // ã�Ҵ�.
	{
		cout << *iter << endl;
	}
	 
	// 2. v���� 25���� ū ���� �ִٸ� �� �ڸ��� ã���ּ���.
	iter = std::find_if(v.begin(), v.end(), &Find_if);

	struct Find_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Find_If_Functor functor1;
	functor1.compareNum = 25;
	iter = std::find_if(v.begin(), v.end(), functor1);

	functor1.compareNum = 27;
	iter = std::find_if(v.begin(), v.end(), functor1);

	cout << *iter << endl;

	// 3. v���� 3�� ������ �����
	int count = std::count(v.begin(), v.end(), 3);
	// 4. v���� 10���� ū ���� �����
	functor1.compareNum = 10;
	count = std::count_if(v.begin(), v.end(), functor1);
	// 5. v���� ��� ���� 50���� ������ all_of
	// 6. v���� �ϳ��� 20���� ũ�� 30���� ���� ���� �ִ��� any_of
	// 7. v�� �迭�� ���ٷ� ������ּ���. reverse
	// 8. �� v�� ���ҿ� 3�� �����ּ���.
	std::for_each(v.begin(), v.end(), Multiple); // FN�� �� ���Ұ� �Ű������� ���� �Լ� �ñ״��ĸ� �������Ѵ�.
	// 9. v�� �������ּ���.
	std::sort(v.begin(), v.end(), less<int>());
	// 10. v���� �ߺ��� ���Ұ� �ִٸ� �������ּ���.
	v.erase(std::unique(v.begin(), v.end()), v.end());
	// 11. v���� 45�� ���Ұ� �ִٸ� ����
	v.erase(std::remove(v.begin(), v.end(), 45));
	
	// 12. v���� 20���� ���� ���ҵ� ����
	struct Remove_IF
	{
		bool operator()(const int& element)
		{
			return element < removeCompare;
		}

		int removeCompare;
	};

	Remove_IF fn;
	fn.removeCompare = 20;
	v.erase(std::remove_if(v.begin(), v.end(), fn), v.end());

	// 57�� iter�� for�� ���鼭 �����
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == 57)
		{
			iter = v.erase(iter);
		}
	}

	return 0;
}