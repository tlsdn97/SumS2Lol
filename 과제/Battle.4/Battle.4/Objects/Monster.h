#pragma once

#include "Creature.h"

class Monster : public Creature
{
public:
	Monster(int hp, int atk);
	~Monster();

private:
	int _hp;
	int _atk;

};

