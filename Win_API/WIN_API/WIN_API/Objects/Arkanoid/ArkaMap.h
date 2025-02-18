#pragma once
class Brick;
class ArkaBall;

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

	Vector _brickGap = Vector(2, 2);
};

