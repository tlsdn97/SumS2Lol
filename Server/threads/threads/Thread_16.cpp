#include "framework.h"

class Player : public RefCountable
{
public:
	Player() { cout << "Player ������ ȣ�� " << endl; }
	~Player() { cout << "Player �Ҹ��� ȣ�� " << endl; }

	void SetTarget(Player* target)
	{
		_target = target;
	}

	void Attack()
	{
		if (_target != nullptr)
		{
			_target->_hp -= _atk;
		}
	}

	bool IsDead()
	{
		return _hp <= 0;
	}


private:
	Player* _target = nullptr;

	int _hp = 10;
	int _atk = 1;
};

void Fight(TSharedPtr<Player> p1, TSharedPtr<Player> p2)
{
	while (true)
	{
		p1->Attack();
		p2->Attack();

		if (p1->IsDead() || p2->IsDead())
			break;
	}
}

int main()
{
	ThreadManager::Create();


	TSharedPtr<Player> p1 = new Player();
	TSharedPtr<Player> p2 = new Player();

	p1->ReleaseRef();
	p2->ReleaseRef();

	TM->Launch([p1,p2]()-> void
	{
		while (true)
		{
			this_thread::sleep_for(1000ms);
			break;
		}

	});

	TM->Join();

	ThreadManager::Delete();

	return 0;
}