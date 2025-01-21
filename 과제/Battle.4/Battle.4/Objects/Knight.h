#pragma once

#include "Objects/Player.h"
class Player;

class Knight : public Player
{
public:
	Knight(int hp, int atk, string name);
	~Knight();

	virtual void Attack(Creature* other) override;

private:
};

