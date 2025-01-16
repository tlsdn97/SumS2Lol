#pragma once
class Creature
{
public:
	Creature(int hp, int atk);
	virtual ~Creature();

	// �����Լ� 
	// - ��ӱ����� ���̴� �Լ� : ��� �ڽ��� �������̵��� ����
	// - �������̵�

	virtual void Attack(Creature* other);
	void TakeDamage(int amount);

	bool IsDead();

	// C# getset
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

protected:
	int _hp;
	int _atk;
	string _name;
};

