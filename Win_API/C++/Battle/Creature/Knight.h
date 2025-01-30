#pragma once

#include "Creature/Player.h"
class Player;

class Knight : public Player, public enable_shared_from_this<Knight>
{
public:
	Knight(int hp, int atk, string name);
	~Knight();

	// �Լ� �������̵�
	virtual void Attack(shared_ptr<Creature> other) override;

private:

};

