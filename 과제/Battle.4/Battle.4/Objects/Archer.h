#pragma once

#include "Objects/Player.h"
class Player;

class Archer : public Player
{
public:
	Archer(int hp, int atk);
	~Archer();

	void Attack(Creature* a);

private:

};

