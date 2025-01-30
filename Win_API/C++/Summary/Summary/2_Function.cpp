#include <iostream>

using namespace std;

// �����Լ�
// y = f(x)
// (��ȯ�ڷ���) �Լ��̸�(�Ű�����) => �Լ� �ñ״���
// �Լ� ������
// void : ������, 

// ������ ������
// *ptr : ����������, ��Ż������ => �����Ͱ� ����ִ� �ּҰ����� ��ŻŸ�� ��
// &(����) : �ּҿ����� => ������ ����ִ� �ּҰ�

// Stack : ������ �ð��� ũ�Ⱑ ����

// ���������� : �Լ��� ȣ�� �� �� Stack������ ���̴� [��ȯ�ּҰ�, �Ű�����, ��������]
// ������, ������ ���̿� ���ؼ� ����
// 
// std::vector, std::list �����غ��� ������

void HelloWorld(void)
{
	cout << "Hello World!" << endl;
}

int Add(int a, int b)
{
	int c = a + b;

	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(cccccccc)), Add[��ȯ�ּҰ�(&aInt), �Ű�����(a 1,b 2), �������� c(3)]
	
	cout << c << endl;

	return c;
}

// C : ���� �̸����� �ٸ� �������� ������ => �Լ� �����ε�
// �ٸ� ���� : �Ű������� �ڷ����̳�, ���� �ٸ� ��
int Add(int a, int b, int c)
{
	int d = Add(a,b) + c;
	return d;
}

// �Լ� �Ű������� �⺻����  => �Ű�����(����, Parameter, Arrgument)
// �⺻���ڴ� �� �ں���
int Add(int a, int b, int c, int d, int e = 1)
{
	int f = Add(a,b,c) + d + e;
	return f;
}

// ���ȣ�� : ���ÿ����÷ο� => ���ÿ� �� �̻� �Ҵ��� ���� ����.
// !5 : 5 x 4 x 3 x 2 x1
int Factorial(int num)
{
	if (num == 1)
		return 1;

	//     5   * 4 * 3 * 2 * 1
	return num * Factorial(num - 1);
}

// �޸������̼�
int cache[200] = {};
int Fibonacci(int num)
{
	if (num == 0 || num == 1)
		return 1;

	int* ref = &cache[num];
	if (*ref != 0)
		return *ref;

	*ref = Fibonacci(num - 1) + Fibonacci(num - 2); // cache[2] = 2

	return *ref;
}

// Call by Value
void AddOne(int num)
{
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3)), AddOne[��ȯ�ּҰ�(&aInt), �Ű�����(num : 3), ��������()]
	num++;
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3)), AddOne[��ȯ�ּҰ�(&aInt), �Ű�����(num : 4), ��������()]
}

// Call by Address
void AddOne(int* ptr)
{
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������((0x12)aInt(3)), AddOne[��ȯ�ּҰ�(&aInt), �Ű�����(ptr : 0x12), ��������()]
	(*ptr)++;
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������((0x12)aInt(4)), AddOne[��ȯ�ּҰ�(&aInt), �Ű�����(ptr : 0x12), ��������()]
}

int main()
{
	HelloWorld();

	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(cccccccc))

	int aInt = Add(1, 2);

	// aInt ... 3
	AddOne(aInt);
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3))
	cout << aInt << endl;

	AddOne(&aInt);
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(4))
	cout << aInt << endl;

	aInt = Add(1, 2, 3, 4);

	aInt = Factorial(5);
	
	aInt = Fibonacci(1000);
	cout << aInt << endl;

	return 0;
}