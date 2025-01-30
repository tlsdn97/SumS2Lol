#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

// ������(l-value), ������(r-value)

// l-value
// - ��������
// - ��ǥ���� ��) ����

// r-value
// - l-value�ƴ� ���
// - ��ǥ���� ��) const, ���

// Shift : �̵�, �̻�
// (�ڷ���)&& : ���������� => C++11

class Pet
{
};

class Player
{
public:
	Player() { pet = new Pet(); }
	Player(int hp) { pet = new Pet(); }
	Player(const Player& other) 
	{ 
		// ���� ����
		this->pet = new Pet(*other.pet);
	}

	// ������ ����
	// 1. ������ ���� ����
	// 2. other�� ���������� ���������� => �����⸸ ����ڴ�.
	// => �Ű����� other�� �ӽð�ó�� ����ϰڴ�.
	Player(Player&& other) noexcept  // �̵�������
	{
		cout << "�̵������� ȣ��" << endl;
		this->pet = other.pet;
		other.pet = nullptr;
	}
	~Player() 
	{
		if(pet != nullptr)
			delete pet; 
	}


private:
	Pet* pet;
};

int& Temp()
{
	int aInt = 1;

	return aInt;
}

int main()
{
	int aInt = 1;
	aInt = 5;
	int& ref = aInt;
	ref = 3233;

	// player1���� player2�� �̻�
	Player* player1 = new Player(std::move(Player()));

	Player* player2 = new Player(std::move(*player1)); // �̵����� : �̻�

	unique_ptr<Player> up = make_unique<Player>();
	unique_ptr<Player> up2(std::move(up));

	//vector<Player> players;
	//players.emplace_back(Player()); // players[0]

	delete player2;
	delete player1;

	return 0;
}