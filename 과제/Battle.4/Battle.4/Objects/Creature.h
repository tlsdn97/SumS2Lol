
class Creature
{
public:
	Creature(int hp, int atk);
	~Creature();

	void Attack(Creature* other);
	void TakeDamage(int amount);

	bool IsDead();

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

protected:
	int _hp;
	int _atk;
	string _name;

};
