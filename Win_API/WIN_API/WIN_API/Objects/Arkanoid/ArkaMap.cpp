#include "framework.h"
#include "ArkaMap.h"

<<<<<<< HEAD
#include "Brick.h"
#include "ArkaBall.h"
=======
#include "ArkaBall.h"
#include "ArkaBar.h"
#include "ArkaBrick.h"
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

ArkaMap::ArkaMap()
{
	_bricks.resize(_countY);

<<<<<<< HEAD
=======
	Vector offset;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
	int x = ((_brickSize.x + _brickGap.x) * _countX) / 2.0f;

	Vector temp = CENTER;
	offset.x = temp.x - x;
	offset.y = 200.0f;

	for (int y = 0; y < _countY; y++)
	{
		for (int x = 0; x < _countX; x++)
		{
<<<<<<< HEAD
			shared_ptr<Brick> bricks = make_shared<Brick>(_brickSize);

			Vector brickPos;
			brickPos.x = _brickSize.x * x;
			brickPos.y = _brickSize.y * y;

			bricks->SetPos(brickPos);
			bricks->_isActive = true;
			_bricks[y].push_back(bricks);
=======
			shared_ptr<ArkaBrick> brick = make_shared<ArkaBrick>(_brickSize);

			Vector brickPos;
			brickPos.x = (_brickSize.x + _brickGap.x) * x;
			brickPos.y = (_brickSize.y + _brickGap.y) * y;

			brick->SetPos(brickPos + offset);
			brick->_isActive = true;
			_bricks[y].push_back(brick);
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
		}
	}
}

ArkaMap::~ArkaMap()
{
}

<<<<<<< HEAD
void ArkaMap::IsCollision_Bricks(shared_ptr<ArkaBall> ball)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			auto rect = brick->GetCollider();
			// if(rect-)

			if (ball->Getpos().x < rect->Right() && ball->Getpos().x > rect->Left())
			{
				Vector curDir = ball->GetDir();
				curDir.y *= -1.0f;
				
				ball->SetDir(curDir);
			}
		}
			
	}
}
=======

>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

void ArkaMap::Update()
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
<<<<<<< HEAD
			brick->GetPos();
		}
	}
=======
			brick->Update();
		}
	}

	
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}

void ArkaMap::Render(HDC hdc)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
<<<<<<< HEAD
			brick->GetPos();
		}
	}
}
=======
			brick->Render(hdc);
		}
	}
}
	

void ArkaMap::IsCollision_Bricks(shared_ptr<ArkaBall> ball)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			if (brick->_isActive == false)
				continue;
			if (brick->GetCollider()->IsCollision(ball->GetCollider()) == false)
				continue;

			brick->Break_Brick();

			if (ball->GetPos().x < brick->GetCollider()->Right() && ball->GetPos().x > brick->GetCollider()->Left())
			{
				Vector curDir = ball->GetDir();
				curDir.y *= -1.0f;

				ball->SetDir(curDir);
			}

			else
			{
				Vector curDir = ball->GetDir();
				curDir.x *= -1.0f;

				ball->SetDir(curDir);
			}
		}
	}
}


>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
