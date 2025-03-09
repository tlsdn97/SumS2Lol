#pragma once

class Brick;
class ArkaBall;


class ArkaBrick;
class ArkaBall;
class ArkaBar;

class ArkaMap
{
public:
	ArkaMap();
	~ArkaMap();

	
	vector<vector<shared_ptr<Brick>>> GetBricks() { return _bricks; }

	void IsCollision_Bricks(shared_ptr<ArkaBall> ball);


	void Update();
	void Render(HDC hdc);

private:
	vector<vector<shared_ptr<Brick>>> _bricks;

	Vector _brickSize = Vector(80, 20);

	int _countX = 5;
	int _countY = 3;

	Vector offset;

	vector<vector<shared_ptr<ArkaBrick>>> GetBrick() { return _bricks; }

	void IsCollision_Bricks(shared_ptr<ArkaBall> ball);


private:
	vector<vector<shared_ptr<ArkaBrick>>> _bricks;
	vector<shared_ptr<class ArkaItem>> _items;

	Vector _brickSize = Vector(80, 20);

	int _countX = 12;
	int _countY = 8;


	Vector _brickGap = Vector(2, 2);
};

