#include "pch.h"
#include "Player.h"

Player::Player(int hp, int atk, string name)
	:Creature(hp,atk)
{
	SetName(name);
}

Player::~Player()
{
}
