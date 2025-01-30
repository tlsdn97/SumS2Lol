#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "List.h"
#include "Vector.h"

int main()
{
	List<int> myList;

	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	myList.push_front(5);
	myList.push_front(6);
	myList.push_front(7);
	myList.push_front(8);
	// 8 7 6 5 1 2 3 4

	myList.pop_front();
	myList.pop_back();

	//myList.insert(100, 3);

	//for (int i = 0; i < myList.size(); i++)
	//{
	//	cout << myList[i] << endl;
	//}

	cout << "------------" << endl;
	Vector<int> myV;
	myV.push_back(1);
	myV.push_back(5);
	myV.push_back(6);
	myV.push_back(2);
	myV.push_back(87);

	myV.pop_back();

	myV.insert(10, 3);

	for (int i = 0; i < myV.size(); i++)
	{
		cout << myV[i] << endl;
	}

	myV.clear();
	//vector<int>().swap(myV); // => �ӽð�ü�� Swap�ؼ� ���� �����͸� ������ �ڵ�
	cout << myV.capacity() << endl; // => Clear�Ѵٰ� �ؼ� _data�� ����Ű�� �ִ� Heap������ �����Ǵ� �� �ƴϴ�.

	return 0;
}