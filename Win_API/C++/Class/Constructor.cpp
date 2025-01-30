#include <iostream>

using namespace std;

// �������� ����
// - �����ڰ� ���ų�, ������ �Ұ����ϸ�, ��üȭ��ų �� ����.
// - ��������� �ʱ�ȭ
// - ����

class Player
{
public:
	// �⺻������ 
	// - �������������� �Ͻ������� �����Ϸ��� �������ش�.
	//  => �ٸ� ������(Ÿ�Ժ�ȯ������)�� ���� ��� �ڵ����� ���������� �ʴ´�.
	Player()
		// ���� �ʱ�ȭ ����(Initialize List)
	: _maxHp(100)
	, _hp(0)
	, _atk(0)
	{
		// ���� �ʱ�ȭ ����
		// _hp = 0; // ���Կ�����
		// _atk = 0;
		cout << "�⺻������ ȣ��" << endl;
	}

	// Ÿ�Ժ�ȯ������(�Ű������� �ִ� ������)
	Player(int hp)
	: _maxHp(hp)
	, _hp(hp)
	, _atk(0)
	{
	}

	//Player(int& hp)
	//: _maxHp(hp)
	//, _temp(hp)
	//{

	//}

	// ���������, ������Ի�����
	// - �⺻�����ڿ� ���������� �Ͻ������� ������ִ� ������
	Player(const Player& other)
	: _maxHp(other._maxHp)
	, _hp(other._hp)
	, _atk(other._atk)
	{
	}

private:
	int _hp;
	int _atk;

	const int _maxHp;
	//int& _temp;
};

int main()
{
	// ��ü : �Ӽ��� ��� ����, �޸𸮿� �Ҵ�Ǿ� �ִ� (Ŭ������ ����) ��
	// ��üȭ,�ν��Ͻ�ȭ : Ŭ������ �޸𸮿� �Ҵ��Ű�� �۾�

	Player p = 100;
	// Player p(100);
	Player p2 = p;
	// Player p2(p);

	return 0;
}