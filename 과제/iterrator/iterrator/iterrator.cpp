﻿#include <iostream>
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

int main()
{
	vector<int> v = { 31, 23, 3, 2, 1, 3, 12, 15, 19 };

	// 1. v에서 23이 있는 원소의 자리(index, iter)를 찾아주세요.
	vector<int>::iterator iter = std::find(v.begin(), v.end(), 23);
	if (iter != v.end()) // 찾았다.
	{
		cout << *iter << endl;
	}

	// 2. v에서 25보다 큰 수가 있다면 그 자리를 찾아주세요.
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

	// 3. v에서 3의 개수가 몇개인지
	bool count_of_3 = 0;
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		if (*iter == 3)
		{
			++count_of_3;
		}
	}
	cout << "3의 개수 : " << count_of_3 << endl;

	// 4. v에서 10보다 큰 수는 몇개인지
	bool count_size_10 = 0;
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		if (*iter > 10)
		{
			++count_size_10;
		}
		cout << "10보다 큰 수의 개수 : " << count_size_10 << endl;
	}
	// 5. v에서 모든 수가 50보다 작은지
	bool all_size_50 = true;
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		if (*iter >= 50)
		{
			all_size_50 = false;
			break;
		}
	}

	if (all_size_50)
	{
		cout << "모두 50보다 작습니다. " << endl;
	}
	else
	{
		cout << "50보다 크거나 같은 수가 있습니다. " << endl;
	}

	// 6. v에서 하나라도 20보다 크고 30보다 작은 수가 있는지
	bool big_or_small = false;
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		if (*iter > 20 && *iter < 30)
		{
			big_or_small = true;
			break;
		}
	}

	if (big_or_small)
	{
		cout << "20보다 크고 30보다 작은 수가 있습니다 " << endl;
	}
	else
	{
		cout << "20보다 크고 30보다 작은 수가 없습니다." << endl;
	}

	// 7. v의 배열을 거꾸로 만들어주세요.
	for (auto iter1 = v.begin(), iter2 = v.end() - 1; iter1 < iter2; ++iter, --iter2)
	{
		std::swap(*iter1, *iter2);
	}

	cout << "거꾸로 된 배열" << endl;
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	// 8. 각 v의 원소에 3을 곱해주세요.
	for (auto& x : v)
	{
		x *= 3;
	}
	cout << "각 원소에 3을 곱한 수 : ";
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	// 9. v를 정렬해주세요.
	std::sort(v.begin(), v.end());

	cout << "정렬된 배열의 수 : ";
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	// 10. v에서 중복된 원소가 있다면 삭제해주세요.
	std::sort(v.begin(), v.end());

	auto list = std::unique(v.begin(), v.end());
	v.erase(list, v.end());

	cout << "중복된 원소 제거한 수 : ";
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	// 11. v에서 45인 원소가 있다면 삭제
	v.erase(std::remove(v.begin(), v.end(), 45), v.end());

	cout << "원소 45를 삭제한 수 : ";
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	// 12. v에서 20보다 작은 원소들 삭제

	for (auto iter = v.begin(); iter != v.end();)
	{
		if (*iter < 20)
		{
			iter = v.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	cout << "20보다 작은 원소들 삭제한 수 : ";
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	return 0;
}