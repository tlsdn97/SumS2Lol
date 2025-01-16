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
	// private 멤버변수에 접근할 수 있는 얘 : 멤버함수

	string _name;
};

