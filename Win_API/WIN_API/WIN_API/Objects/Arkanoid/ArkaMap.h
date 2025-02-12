#pragma once

class ArkaBrick;
class ArkaBall;
class ArkaBar;

class ArkaMap
{
public:
	ArkaMap();
	~ArkaMap();

	void Init(shared_ptr<ArkaBar> bar);

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<ArkaBrick>>> GetBrick() { return _bricks; }

	void IsCollision_Bricks(shared_ptr<ArkaBall> ball);
	void GetItems(shared_ptr<ArkaBar> bar);

private:
	vector<vector<shared_ptr<ArkaBrick>>> _bricks;
	vector<shared_ptr<class ArkaItem>> _items;

	Vector _brickSize = Vector(80, 20);

	int _countX = 9;
	int _countY = 6;

	Vector _brickGap = Vector(2, 2);
};

