#include <iostream>

using namespace std;

// ������(Ŭ���� �������� ���¸� ���� �� �ִ�.)
// 1. ����Լ� �������̵� : �θ��� �Լ��� �ڽĿ��� ������(�Լ��ñ״��İ� ����)�ϴ� ��
// 2. ����Լ� �����ε� : �Լ��� �̸��� ����, �Ű������� ������ �ڷ����� �ٸ� �Լ��� ������ �� �ִ�.

class Player
{
public:
	void Attack() { cout << "ATTACK!!!" << endl; }

	void Set(int hp, int atk) { _hp = hp; _atk = atk; }

	// ������ �����ε�
	// a + b : a�� b�� ���ϰ� �ӽð��� ��ȯ�Ѵ�.
	Player operator+(const Player& other)
	{
		Player result;
		result._hp = _hp + other._hp;
		result._atk = _atk + other._atk;

		return result;
	}

	void operator()()
	{
		cout << "Hello I'm Player!!" << endl;
	}

protected:
	int _hp;
	int _atk;
};

class Knight : public Player
{
public:
	void Attack() { cout << "Knight!!!" << endl; } // �Լ� �������̵�
};

int main()
{
	Knight knight;
	knight.Attack();

	Player p1;
	Player p2;
	Player p3 = p1 + p2; // +������ �����ε�

	p3();

	int aInt = 1;
	int bInt = 2;
	int cInt = aInt + bInt;

	return 0;
}