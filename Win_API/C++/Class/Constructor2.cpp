#include <iostream>

using namespace std;

class Player
{
public:
	Player(int hp) : _hp(hp), _atk(0) { cout << "Ÿ�Ժ�ȯ ������ ȣ��" << endl; }
	
	// ����
	// 1. �����Ҵ� ����
	// 2. �Ҹ�ó��
	~Player() { cout << "�Ҹ��� ȣ��" << endl; }

protected:
	int _hp;
	int _atk;
};

class Knight : public Player
{
public:
	Knight() 
	// �����ʱ�ȭ �������� �θ��� �����ڸ� �Ͻ������� ȣ���Ѵ�.
	// ��������� ���� ȣ������ ���� �ִ�.
	: Player(150) 
	{ 
		cout << "Knight �⺻������ ȣ��" << endl; 
	}

	~Knight() { cout << "Knight �Ҹ��� ȣ��" << endl; }
};

int main()
{
	Knight k;

	return 0;
}