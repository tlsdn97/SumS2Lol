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
	// �޸� ���� �߻�-> 7�ϸ��� �����ؼ� ����
	// �޸� ���� �߻�-> ����

	// StompAllocator�� �̿��Ͽ� �޸� ���� ���� -> Debug
	Player* p = xnew<Player>();

	p->_hp = 10;

	//Knight* k = reinterpret_cast<Knight*>(p);
	//k->_stamina = 5;

	xdelete(p);

	//p->_hp = 5;

	// STLAllocator�� �̿��Ͽ� STL�� Container�� �� �� �޸� ���� �� ��������� ����
	// Vector<Player> players = {Player(), Player(), Player()};

	MemoryPool pool1(100);

	MemoryHeader* header = pool1.Pop();
	Player* p1 = reinterpret_cast<Player*>(MemoryHeader::AttachHeader(header, sizeof(Player)));

	p1->_hp = 100;
	p1->_atk = 10;

	ThreadManager::Delete();

	return 0;
}