#pragma once

// h�� �����
// h, cpp ����
// => ��Ŀ

// ���漱��
#include "Creature/Creature.h"

class Creature;
// #include �� ���� �ʴ� ����

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();

};
