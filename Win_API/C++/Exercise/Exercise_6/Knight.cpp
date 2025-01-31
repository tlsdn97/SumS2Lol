#include "Knight.h"
#include <iostream>
using namespace std;

// [��缭] �⺻�� Hp=100, Attack=10
Knight::Knight() : _hp(100), _maxHp(100), _attack(10), _count(0)
{

}

Knight::Knight(int hp) : _hp(hp), _maxHp(hp), _attack(10), _count(0)
{

}

Knight::~Knight()
{

}

void Knight::AddHp(int value)
{
	_hp += value;
	if (_hp < 0)
		_hp = 0;
	if (_hp > _maxHp)
		_hp = _maxHp;
}

bool Knight::IsDead()
{
	return (_hp <= 0);
}

int Knight::GetAttackDamage()
{
	int damage = _attack;

	if (_maxHp > 0)
	{
		int percentage = (100 * _hp) / _maxHp;
		if (percentage <= 50)
			damage *= 2;
	}

	return damage;
}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}

void Knight::OnDamaged(Knight* attacker, int count)
{

	if (attacker == nullptr)
		return;

	if (count >= 4) return;

	count++;

	// �� ü�� ��´�
	int damage = attacker->GetAttackDamage();
	AddHp(-damage);
	cout << "Reflection" << endl;

	// �ݰ�!
	attacker->OnDamaged(this, count);	
}