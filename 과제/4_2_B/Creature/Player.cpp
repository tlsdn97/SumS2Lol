#include "pch.h"

#include "Player.h"
#include "Creature.h"

Player::Player(int hp, int atk, string name)
	: Creature(hp, atk)
	, _name(name)
{
}

Player::~Player()
{
}
