#include "pch.h"

#include "Creature.h"
#include "Player.h"

// cpp ����
Player::Player(int hp, int atk, string name)
: Creature(hp, atk)
{
	SetName(name);
}

Player::~Player()
{
}

