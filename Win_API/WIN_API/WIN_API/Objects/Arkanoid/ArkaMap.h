#pragma once
<<<<<<< HEAD
class Brick;
class ArkaBall;
=======

class ArkaBrick;
class ArkaBall;
class ArkaBar;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

class ArkaMap
{
public:
	ArkaMap();
	~ArkaMap();
<<<<<<< HEAD
	
	vector<vector<shared_ptr<Brick>>> GetBricks() { return _bricks; }

	void IsCollision_Bricks(shared_ptr<ArkaBall> ball);
=======
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

	void Update();
	void Render(HDC hdc);

<<<<<<< HEAD
private:
	vector<vector<shared_ptr<Brick>>> _bricks;

	Vector _brickSize = Vector(80, 20);

	int _countX = 5;
	int _countY = 3;

	Vector offset;
=======
	vector<vector<shared_ptr<ArkaBrick>>> GetBrick() { return _bricks; }

	void IsCollision_Bricks(shared_ptr<ArkaBall> ball);


private:
	vector<vector<shared_ptr<ArkaBrick>>> _bricks;
	vector<shared_ptr<class ArkaItem>> _items;

	Vector _brickSize = Vector(80, 20);

	int _countX = 9;
	int _countY = 6;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

	Vector _brickGap = Vector(2, 2);
};

