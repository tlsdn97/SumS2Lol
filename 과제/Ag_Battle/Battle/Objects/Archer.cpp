#include "framework.h"
#include "Archer.h"

Archer::Archer(int hp, int attack, string name)
	: Player(hp, attack, name)
{
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* other)
{
	cout << this->_name << "�̰� " << other->GetName() << "���� ������ �õ��մϴ�." << endl;

	int randNum = rand() % 100;
	if (randNum <= 49)
	{
		cout << this->_name << "�� ũ��Ƽ�� ����" << endl;
		other->TakeDamage(this, this->_attack * 2.0f);
	}
	else
		other->TakeDamage(this, this->_attack);
}