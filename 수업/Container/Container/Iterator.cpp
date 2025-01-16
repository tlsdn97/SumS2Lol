#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "List.h"
#include "Vector.h"

// iterator : �ݺ��� (��ȸ��)

int main()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	// vector�� �������ٿ����ڷ� ��ȸ�� �����ϴ�. <-> list�� ��ȸ�Ұ���
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	// vector�� iter�� ��ȸ�ϴ� ���
	Vector<int>::Iterator iter;
	iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	iter = v.begin();

	return 0;
}