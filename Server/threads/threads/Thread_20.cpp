#include "framework.h"

class Player
{
public:

	Player() { cout << "Player�� ������ ȣ��" << endl; }
	~Player() { cout << "Player�� �Ҹ��� ȣ��" << endl; }

public:

	int _hp = 0;
	int _atk = 0;
};

class Knight : public Player
{
public:

	Knight() { cout << "Knight�� ������ ȣ��" << endl; }
	~Knight() { cout << "Knight�� �Ҹ��� ȣ��" << endl; }

public:

	int _stamina = 0;
};

int main()
{
	ThreadManager::Create();

	Knight* k = xnew<Knight>();

	xdelete(k);

	ThreadManager::Delete();

	return 0;
}