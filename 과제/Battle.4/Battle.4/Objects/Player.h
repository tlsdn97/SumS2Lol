#pragma once

#include "Objects/Creature.h"

class Creature;

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();

};

