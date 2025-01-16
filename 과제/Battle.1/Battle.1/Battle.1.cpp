#include <iostream>

using namespace std;

struct Player
{
	string name;
	int hp;
	int atk;
};

void PrintPlayer(const Player* const p)
{
	cout << "NAME : " << p->name << endl;
	cout << "HP : " << p->hp << endl;
	cout << "ATK : " << p->atk << endl;
}

void SetPlayer(Player* p, string name, int hp, int atk)
{
	p->hp = hp;
	p->name = name;
	p->atk = atk;
}

void Attack(Player* attacker, Player* victim)
{
	victim->hp -= attacker->atk;
	cout << attacker->name << " 가 " << victim->name << " 에게  " << attacker->atk << " 만큼 공격했습니다. " << endl;
}

void Fight(Player* p1, Player* p2)
{
	while (p1->hp > 0 && p2->hp > 0)
	{
		Attack(p1, p2);
		if (p2->hp <= 0)
		{
			cout << p2->name << " 가 패배하여 " << p1->name << " 의 승리입니다" << endl;
			break;
		}

		Attack(p2, p1);
		if (p1->hp <= 0)
		{
			cout << p1->name << " 가 패배하여 " << p2->name << " 의 승리입니다" << endl;
			break;
		}
	
	}
}

int main()
{
	Player p1;
	p1.hp = 0;
	p1.atk = 0;

	Player p2;
	p2.hp = 0;
	p2.atk = 0;

	SetPlayer(&p1, "hanill", 100, 13);
	SetPlayer(&p2, "hanill2", 150, 10);

	Attack(&p1, &p2);
	Fight(&p1, &p2);

	PrintPlayer(&p1);
	PrintPlayer(&p2);

	return 0;
}