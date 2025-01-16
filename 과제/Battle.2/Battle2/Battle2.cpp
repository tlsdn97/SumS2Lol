#include <iostream>	

using namespace std;

// 과제2 Battle
//
class Player
{
public:

	void SetPlayer(Player* p, string name, int hp, int atk)
	{
		p->_hp = hp;
		p->_name = name;
		p->_atk = atk;
	}

	void PrintPlayer(const Player* const p)
	{
		cout << "NAME : " << p->_name << endl;
		cout << "HP : " << p->_hp << endl;
		cout << "ATK : " << p->_atk << endl;
	}


	void Fight()
	{
		while (p1->_hp < 0 && p2->_hp > 0)
		{
			Attack(p1, p2);
			if (p2->hp <= 0)
			{
				cout << p2->_name << " 가 패배하여 " << p1->_name << " 의 승리입니다" << endl;
				break;
			}

			Attack(p2, p1);
			if (p1->hp <= 0)
			{
				cout << p1->_name << " 가 패배하여 " << p2->_name << " 의 승리입니다" << endl;
				break;
			}
		}
	}

	void Attack(Player* attacker, Player* victim)
	{
		victim->_hp -= attacker->_atk;
		cout << attacker->_name << " 가 " << victim->_name << " 에게  " << attacker->_atk << " 만큼 공격했습니다. " << endl;
	}


private:
	string _name;
	int _hp;
	int _atk;
};

int main()
{
	

	return 0;
}