#include "framework.h"
#include "Mage.h"

Mage::Mage(int hp, int attack, string name)
	:Player(hp, attack, name)
{
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* other)
{
	cout << this->_name << "��(��) " << other->GetName() << "���� ������ �õ��մϴ�." << endl;

	int randNum = rand() % 4;

	if (randNum == 0)
	{
		cout << this->_name << "�� ������ 3���� ����" << endl;
		other->TakeDamage(this, this->_attack * 3.0f);
	}
	else
		other->TakeDamage(this, this->_attack);
}



