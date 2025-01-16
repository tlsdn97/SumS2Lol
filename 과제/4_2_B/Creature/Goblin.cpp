#include "pch.h"

#include "Creature.h"
#include "Monster.h"
#include "Knight.h"
#include "Goblin.h"


Goblin::Goblin()
	: Monster(50, 5)
	, _name("Goblin")
{
}

Goblin::Goblin(int hp, int atk, string name)
	: Monster(hp, atk)
{
}

Goblin::~Goblin()
{
}

void Goblin::Attack(Knight* other)
{
	cout << _name << " Goblin Attack!!!" << endl;
	other->TakeDamage(_atk);
}
