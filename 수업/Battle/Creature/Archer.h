#pragma once
#include "Creature/Player.h"

class Archer :	public Player
{
public:
	Archer(int hp, int atk, string name);
	~Archer();

	virtual void Attack(Creature* other) override;


private:
};

