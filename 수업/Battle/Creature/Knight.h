#pragma once

#include "Creature/Player.h"
class Player;

class Knight : public Player
{
public:
	Knight(int hp, int atk, string name);
	~Knight();

	// �Լ� �������̵�
	virtual void Attack(Creature* other) override;

private:

};

