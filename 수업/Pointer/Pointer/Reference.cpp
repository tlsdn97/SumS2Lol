#include <iostream>

using namespace std;

// Reference : ����
// (�ڷ���) & (�����̸�) = (�ʱ�ȭ);

// - ������� ����
// => ������ �۾�

// c++ ����
// ptr
// 1. �����ϴ� (nullptr�� ����, �ʱ�ȭ �������� �������� ����)
// 2. ���� ��ƴ�.
// 
// ref
// 1. �������� ��Ī
// => nullptr ������ �Ұ��� �ϴ�.
// => �ݵ�� ��ȿ�� ������ �����̿����Ѵ�.
// 2. ���� ����.

// ptr 
// - ����
// = > nullptr�� ����ų �� �ִ�.

// ref 
// - ����
// => ���� ����.


void PrintRef(int& ref)
{
	cout << ref << endl;
}

int main()
{
	int aint = 1;
	int bint = 2;
	int* ptr = &aint;
	int& ref = aint;

	ref++;
	(*ptr)++;

	PrintRef(aint);
	PrintRef(bint);

	return 0;
}