#include <iostream>
#include <list>

using namespace std;

// vector
// - Heap�� �迭�� �����.(�������, ����, ����, ������ �ݺ��Ѵ�.)
// list
// - Node�������� ���θ� �մ´�.

// vector�� list ����
// 1. ���������ϴµ� �ɸ��� �ð�(vector: ���, list : N)
// 2. �߰����Կ� �ɸ��� �ð�(vector : N, list : (�����Ϸ��� prev��� Ȥ�� next��带 �˰��ִ� ��� ���)
// 3. �޸��� ����ȭ�� ���� �� ũ�Ⱑ ū vector�� ������� ���� ���� �ִ�. 

int main()
{
	list<int> l;
	
	l.push_back(1);
	l.push_back(111);
	l.push_back(113);
	l.push_back(13);
	l.push_front(2);
	l.push_front(340);
	l.push_front(2);
	l.push_front(3);

	list<int>::iterator iter = l.begin();
	for (iter; iter != l.end(); iter++)
	{
		cout << *iter << endl;
	}

	return 0;
}