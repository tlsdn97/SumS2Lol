#include <iostream>

using namespace std;

// ����
// 1. ��� ������ 3����
// 2. ������ ����
// 3. �迭, �迭�� �������� �������

struct Player
{
	// �������
	int hp;
	int atk;
};

// Call By Value
//void PrintPlayer(Player p) // 8 ~~~ ����Ʈ ����
//{
//	cout << p.hp << endl;
//	cout << p.atk << endl;
//}

void PrintPlayer(Player* ptr) // 4����Ʈ
{
	cout << (*ptr).hp << endl;
	cout << (*ptr).atk << endl;
}

void PrintPlayer(Player& p) // 4 ����Ʈ ����
{
	cout << p.hp << endl;
	cout << p.atk << endl;
}

void SetPlayer(Player* p, int hp, int atk)
{
	(*p).hp = hp;
	(*p).atk = atk;
}

void SetPlayer(Player& p, int hp, int atk)
{
	p.hp = hp;
	p.atk = atk;
}

int main()
{
	// . : ������ٿ�����
	Player player;
	player.hp = 1;
	player.atk = 2;

	Player* ptr = &player;
	Player& ref = player;

	SetPlayer(player, 100, 5);
	//SetPlayer(&player, 100, 5);

	PrintPlayer(&player);

	return 0;
}