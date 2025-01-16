#include "pch.h"

#include "Player.h"
#include "Creature.h"

// ccp 정의
Player::Player(int hp, int atk)
{
	cout << "생성자 호출" << endl;
}

Player::~Player()
{
}

void Player::Attack(Monster* victim)
{
	victim->
}



void Player::Attack(Player* victim)
{
}

void Player::TakeDamhge(int amount)
{
}

bool Player::IsaAlive()
{
	return false;
}
