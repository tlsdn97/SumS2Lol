#pragma once

#include "Creature/Player.h"

class Player;

class Knight : public Player
{
public:
	Knight(int hp, int atk, string name);
	~Knight();

	// �Լ� �������̵�
	void Attack(Creature* other);
	void Attack(class Goblin* other);

private:
};

