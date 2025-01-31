#include <iostream>

#define PI 3.141592f

using namespace std;

// ������ 4�ܰ�
// 1. ��ó����
//		- # ��� ó��, �ּ�
// 2. �����Ϸ�
//      - ����� ���(C++)�� �������� �ٲٴ� �۾�
// 3. �����
//		- ������ ����� �ٲٴ� �۾�
// 4. ��Ŀ
//      - ���ϰ����� �ؼ� �����ܰ� .obj ��ȯ�۾�

// ref
// (�ڷ���)& (Ref �̸�) = (�ʱ�ȭ);
// - C++ ���� : �ش� ������ ����
// - ������� : �����Ͷ� �����ϴ�.
// - ũ�� : 32��Ʈȯ��(4����Ʈ) 64��Ʈȯ��(8����Ʈ)

// ptr, ref ����
// 1. �����ʹ� �߰��� ����� ������ �� �ִ� / Ref�� �߰��� ����� ������ �� ����.
// 2. �����ʹ� nullptr�� ������ �� �ִ�. / Ref ���� ���� ������ �� �ִ�.
// 3. �����ʹ� �ʱ�ȭ�� �����ʾƵ� �ȴ�. / Ref�� ������ �ʱ�ȭ

// Call By Value
// �Ű����� value�� �б�, ���� �����ϴ�.
// ������ ������ �� ����. / ������ �о����(����)�� �����ϴ�
//void AddOne(int value)
//{
//	value++;
//}

// Call By Address
// �Ű����� ptr�� Ÿ�� ���� �б�/ ���� ����
// ������ ������ �� �ִ�.
// -> �����ƴ�(�޸� ����)
void AddOne(int* ptr) // 0x12
{
	(*ptr)++;
}

// Call By Reference
// �Ű����� ref(����)�� ���� �б�/ ���� ����
// ������ ������ �� �ִ�.
// -> ���� ����
void AddOne(int& ref)
{
	ref++;
}

int main()
{
	float pi = PI;
	int aInt = 1;
	int bInt = 2;

	int* ptr = &aInt;//0xcccccccc
	ptr = NULL;

	int& ref = aInt;
	ref = 2; 

	cout << aInt << endl;
	cout << ref << endl;
	cout << bInt << endl;

	aInt = 1;
	AddOne(&aInt); // (0x12)aInt
	AddOne(aInt);

	cout << aInt << endl;

	return 0;
}