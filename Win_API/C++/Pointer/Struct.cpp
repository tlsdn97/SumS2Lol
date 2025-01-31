#include <iostream>

using namespace std;

// . : ���������
// -> : ������������� ( * .)

struct Player
{
	// ��� ����
	string name;
	int hp;
	int atk;
};

// Call By Value
// ����
// => ������ ������ �� ����.
// => �Ű������� �����ϴ� ����Ʈ�� ũ��.
//void PrintPlayer(Player p)
//{
//	cout << "NAME : " << p.name << endl;
//	cout << "HP : " << p.hp << endl;
//	cout << "ATK : " << p.atk << endl;
//}

// Call By Address
// => ������ ������ �� �ִ�.
// => nullptr�� ���� �� �ִ�.

// ����
// => nullptr üũ
void PrintPlayer(const Player* const p)
{
	if (p == nullptr) return;

	cout << "NAME : " << p->name << endl;
	cout << "HP : " << p->hp << endl;
	cout << "ATK : " << p->atk << endl;
}

// Call By Reference
// => ������ ������ �� �ִ�.
// => ���� ����.

// ����
// => Call By Value�� ������ �� ����.
void PrintPlayer(const Player& p) // => C++ �б�����
{
	cout << "NAME : " << p.name << endl;
	cout << "HP : " << p.hp << endl;
	cout << "ATK : " << p.atk << endl;
}

void SetPlayer(Player* p, string name, int hp, int atk)
{
	p->name = name;
	p->hp = hp;
	(*p).atk = atk;
}

void SetPlayer(Player& p, const string& name, int hp, int atk)
{
	p.name = name;
	p.hp = hp;
	p.atk = atk;
}

int main()
{
	Player p;
	p.name = "";
	p.hp = 1;
	p.atk = 2;
	PrintPlayer(p);


	return 0;
}