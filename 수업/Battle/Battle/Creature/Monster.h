#pragma once

class Creature;

class Player;

class Monster
{
public:
	Monster();
	~Monster();

	void Attack(Player* victim);

	void TakeDamage(Monster* amount);


private:
	int _hp;
	int _atk;
};

