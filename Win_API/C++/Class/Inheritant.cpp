#include <iostream>

using namespace std;

// ���
// - �ڵ��� ���뼺
// - is a ���谡 ������ ���� ����� �Ǵ�. �ܹ���
// => Animal is a Cat(X)
// => Cat is a Animal(O)
// 
// ...
// 1. ����� �ɸ� ������
// 2. ����� �ɸ� �θ��� �Ӽ�, ����� �����޴´�. 

class Animal
{
public:
	void Eat() { cout << "����" << endl; }
	void SetAnimal(int legs, int mouth)
	{
		_legs = legs;
		_mouth = mouth;
	}
protected:
	int _legs;
	int _mouth;
};

class Cat : public Animal
{
public:
	// �Լ� �������̵� : �θ��� �Լ��� �ڽĿ��� ������
	void Eat()
	{
		cout << "�ɳ�" << endl;
	}

	void SetTail(int tail)
	{
		_tail = tail;
	}

private:
	int _tail;
};

int main()
{
	Animal animal;
	animal.SetAnimal(2, 1);
	animal.Eat();

	Cat cat;
	cat.SetAnimal(4, 1);
	cat.SetTail(1);
	cat.Eat();

	return 0;
}