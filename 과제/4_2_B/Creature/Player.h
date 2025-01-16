#pragma once

class Creature;


class Player :public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();

protected:
	string _name;

};
