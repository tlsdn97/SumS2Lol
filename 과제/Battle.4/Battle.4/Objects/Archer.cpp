#include "pch.h"

#include "Creature.h"
#include "Player.h"
#include "Goblin.h"
#include "Archer.h"

Archer::Archer(int hp, int atk)
	: Player(hp, atk, name)
{
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* a)
{
}
