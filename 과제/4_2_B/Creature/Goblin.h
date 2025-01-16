#pragma once
#include "Monster.h"
class Knight;

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(int hp, int atk, string name);
	~Goblin();

	void Attack(Knight* other);

	// C# getset
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

private:
	// private ��������� ������ �� �ִ� �� : ����Լ�

	string _name;
};

