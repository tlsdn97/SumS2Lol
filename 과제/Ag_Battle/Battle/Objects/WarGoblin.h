#pragma once

struct PlayerInfo
{
	Creature* _player;
	int _totalDamage;
};

class WarGoblin : public Goblin
{
public:
	WarGoblin(int hp, int attack, string name);
	~WarGoblin();

	virtual void Attack(Creature* other) override;
	void RangeAttack();
	virtual void TakeDamage(Creature* attacker, int amount) override;

private:
	vector<PlayerInfo> _playerTable;
};

