#include <iostream>
#include <vector>

using namespace std;

// ĳ���� : ����ȯ
// �Ϲ��� ĳ����
// int -> float (����)
// float -> int (�Ҿ���)
// char -> int (����)
// int -> char (�Ҿ���) => ũ�Ⱑ ū �ڷ������� ���� �ڷ������� ĳ������ �� ��Ʈ�� ���ư��Ƿ� �Ҿ���


// class ���赵
// ��ü(�ǹ�)�� ���� ���赵
// ��ü
// - �Ӽ�(�������)�� ���(����Լ�)�� ����, �޸𸮿� �Ҵ�Ǿ��ִ� ��
//   attribute        method

// ��ĳ����
// - �ڽ� ��ü�� �θ� �����Ͱ� ����Ű�� �� �� �ִ�. => ����
// �ٿ�ĳ����
// - �θ��� ��ü�� �ڽ������Ͱ� ����ų �� �ִ�. => �Ҿ���

// ĳ���� 4�ѻ�
// - static_cast
//  : �������� OK�� ���
//  => �������� �����ų ���ΰ�?
// 
// - dynamic_cast
//  : ��ӱ�������, RTTI�� ������ ���
//  - RTTI : Runtime Type Information
// => ���� �߿� �����ų ���̳�?
// ==> ĳ���ÿ� �����ϸ� nullptr�� ��ȯ
// 
// - const_cast
// - reinterpret_cast
// => C��Ÿ���� ��������ȯ, 

class Player
{
public:

	// �����Լ��� �����ϸ�
	// �����Լ����̺�(vftable) �����
	// ��ü�� �� ���ּҿ��� �����Լ����̺��� ����Ű�� �����Ͱ� �����. => ���� �߿� Ÿ���� �������� Ȯ���� �� �ִ�.
	// -> RTTI
	virtual void Hello() { cout << "Im Player" << endl; }

	int type = 0;
	int _hp = 1;
	int _atk = 2;
};

class Knight : public Player
{
public:
	virtual void Hello() { cout << "Im Knight" << endl; }
	void Attack() {}

	int type = 1;
	int _stamina = 3;
};

int main()
{
	int aInt = static_cast<int>(1.5f); // C++ ���ؿ��� ���ؼ�
	float aFloat = 1.0f;
	int* ptr = reinterpret_cast<int*>(&aFloat);
	aInt = 455555;
	char aChar = aInt;

	cout << aInt << endl;
	cout << *ptr << endl;

	Player* p = new Player();
	Knight* k2 = static_cast<Knight*>(new Player()); // �ٿ�ĳ����
	Player* k = new Knight(); // ��ĳ����

	Knight* dynamicK = dynamic_cast<Knight*>(k); 
	if (k->type == 1)
	{
		static_cast<Knight*>(k);
	}

	if (dynamicK != nullptr)
	{
		// ���� Knight
		dynamicK->Hello();
		dynamicK->Attack();
	}
	else
	{
		// Knight�� �ƴϿ���.
	}

	const char* str = "Hello"; // rodata
	char* str2 = const_cast<char*>(str);
	// str2[0] = 'K'; // rodata������ H�� K�� �ٲ���,

	return 0;
}