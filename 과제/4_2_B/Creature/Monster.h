#pragma once

#include "Creature.h"

class Monster : Creature
{
public:
	Monster(int hp, int atk);
	~Monster();

protected:
	int _hp;
	int _atk;

};

