#include <iostream>
#include <functional>

using namespace std;

function<void(void)> fn; // Callable ��ü�� ���� �� �ִ� ����
void Hello()
{
	cout << "Hello World!" << endl;
}

// Functor : �Լ���ü
struct Functor
{
	// �Լ������� �����ڿ����ε�
	void operator()()
	{
		cout << aInt << endl;
		cout << "Hello World" << endl;
	}

	// �Ӽ��� ���� �� �ִ�.
	int aInt;
};

struct Functor2
{
	int operator()()
	{
		return a + b;
	}

	int a;
	int b;
};

int main()
{
	// �׷��� �Լ� ������ ����, ��� �� �� ����?
	Functor functor;
	functor.aInt = 1;
	functor();
	functor.aInt = 2;
	functor();

	Functor2 functor2;
	functor2.a = 1;
	functor2.b = 2;
	int cInt = functor2();
	

	return 0;
}