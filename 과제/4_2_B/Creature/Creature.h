#pragma once
class Creature
{
public:
	Creature(int hp, int atk);
	~Creature();

	void Attack(Creature* other);
	void TakeDamage(int amount);

	bool IsDead();

protected:
	int _hp;
	int _atk;

};

