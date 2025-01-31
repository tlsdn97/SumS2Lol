#include "pch.h"
#include "Boss.h"

#include "Creature.h"
#include "Player.h"

Boss::Boss()
: Monster(300, 5)
{
	_name = "Hope Goblin";
}

Boss::~Boss()
{
}

void Boss::Attack(shared_ptr<Creature> other)
{
	if (IsDead()) return;

	cout << _name << " Boss Attack!!!" << endl;
	other->TakeDamage(_atk);
}

void Boss::AttackAggro()
{
	if (IsDead()) return;

	// 4�� ������ ���
	if (_aggroTable.size() <= 4)
	{
		for (auto info : _aggroTable)
		{
			Attack(info.player.lock());
		}

		return;
	}

	// ���� 4��
	std::partial_sort(_aggroTable.begin(), _aggroTable.begin() + 4, _aggroTable.end());
	for (int i = 0; i < 4; i++)
	{
		Attack(_aggroTable[i].player.lock());
	}

	// �÷��̾ ����� ����
	auto removeIter = std::remove_if(_aggroTable.begin(), _aggroTable.end(), [](const PlayerInfo& info)-> bool 
		{
			if (info.player.lock()->IsDead())
				return true;
			return false;
		});

	_aggroTable.erase(removeIter, _aggroTable.end());
}

void Boss::TakeDamage(int damage, shared_ptr<Creature> attacker)
{
	// ������ �޾Ҵ�.
	// �÷��̾ �´��� Ȯ��
	shared_ptr<Player> player = dynamic_pointer_cast<Player>(attacker);
	if (player == nullptr)
		return;

	Creature::TakeDamage(damage);

	// 1. aggroTable���� attacker�ִ��� ã�ƺ��߰ڴ�.
	auto iter = find_if(_aggroTable.begin(), _aggroTable.end(), [player](const PlayerInfo& info)-> bool
		{
			if (info.player.lock() == player)
			{
				return true;
			}

			return false;
		});

	// ó�� ���� ���.
	if (iter == _aggroTable.end())
	{
		PlayerInfo info;
		info.player = player;
		info.totalDamage = damage;

		_aggroTable.push_back(info);
	}
	else
	{
		iter->totalDamage += damage;
	}
}
