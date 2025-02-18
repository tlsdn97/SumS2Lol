#include "framework.h"
#include "Knight.h"

Knight::Knight(int hp, int attack, string name)
	:Player(hp, attack, name)
	, _maxHp(hp)
{
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	cout << this->_name << "��(��) " << other->GetName() << "���� ������ �õ��մϴ�." << endl;

	float ratio = (float)_hp / (float)_maxHp;
	if (ratio >= 0.5f)
	{
		other->TakeDamage(this, this->_attack);
	}
	else if (ratio < 0.5f)
	{
		cout << "ü���� ���� Knight�� 2���� ����" << endl;
		other->TakeDamage(this, this->_attack * 2.0f);
	}
}
