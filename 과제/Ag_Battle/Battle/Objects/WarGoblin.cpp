#include "framework.h"
#include "WarGoblin.h"

WarGoblin::WarGoblin(int hp, int attack, string name)
	: Goblin(hp, attack, name)
{
}

WarGoblin::~WarGoblin()
{
}

void WarGoblin::Attack(Creature* other)
{
	cout << this->_name << "이가 " << other->GetName() << "에게 공격을 시도합니다." << endl;
	other->TakeDamage(this, this->_attack);
}

void WarGoblin::RangeAttack()
{
	auto removeIter = std::remove_if(_playerTable.begin(), _playerTable.end(), [](const PlayerInfo& player) -> bool
		{
			if (player._player->IsDead() == true)
				return true;
			return false;
		});

	_playerTable.erase(removeIter, _playerTable.end());

	std::sort(_playerTable.begin(), _playerTable.end(), [](const PlayerInfo& aPlayer, const PlayerInfo& bPlayer) -> bool
		{
			if (aPlayer._totalDamage > bPlayer._totalDamage)
				return true;
			return false;
		});

	for (int i = 0; i < 4; i++)
	{
		if (i >= _playerTable.size())
			break;
		Creature* curPlayer = _playerTable[i]._player;
		this->Attack(curPlayer);
	}
}

void WarGoblin::TakeDamage(Creature* attacker, int amount)
{
	auto iter = std::find_if(_playerTable.begin(), _playerTable.end(), [attacker](const PlayerInfo& info) -> bool
		{
			if (info._player == attacker)
				return true;
			return false;
		});

	if (iter == _playerTable.end())
	{
		PlayerInfo curInfo;
		curInfo._player = attacker;
		curInfo._totalDamage = amount;

		_playerTable.push_back(curInfo);
	}
	else
		iter->_totalDamage += amount;

	int afterHp = _hp - amount;
	SetHp(afterHp);
	cout << _name << "이 " << attacker->GetName() << "에게 " << amount << "만큼의 데미지를 입었습니다." << endl;
}
