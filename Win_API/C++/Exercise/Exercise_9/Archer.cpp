#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp)
{
}

Archer::~Archer()
{
}

void Archer::AddHp(int value)
{
	Player::AddHp(value);

	// �׾����� �굵 ������
	if (IsDead())
	{
		_pet = nullptr;
	}
}
