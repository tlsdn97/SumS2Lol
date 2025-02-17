#pragma once
class World
{
public:
	World();
	~World();

	void Init();
	void Update();
	void CreatePlayers();

	bool End();

	bool IsPlayerAllDead();

private:
	Creature* _warGoblin;
	vector<Creature*> _players;
};

