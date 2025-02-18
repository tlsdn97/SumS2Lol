#include "framework.h"
#include "ArkaMap.h"

#include "Brick.h"
#include "ArkaBall.h"

ArkaMap::ArkaMap()
{
	_bricks.resize(_countY);

	int x = ((_brickSize.x + _brickGap.x) * _countX) / 2.0f;

	Vector temp = CENTER;
	offset.x = temp.x - x;
	offset.y = 200.0f;

	for (int y = 0; y < _countY; y++)
	{
		for (int x = 0; x < _countX; x++)
		{
			shared_ptr<Brick> bricks = make_shared<Brick>(_brickSize);

			Vector brickPos;
			brickPos.x = _brickSize.x * x;
			brickPos.y = _brickSize.y * y;

			bricks->SetPos(brickPos);
			bricks->_isActive = true;
			_bricks[y].push_back(bricks);
		}
	}
}

ArkaMap::~ArkaMap()
{
}

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

void ArkaMap::Update()
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			brick->GetPos();
		}
	}
}

void ArkaMap::Render(HDC hdc)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			brick->GetPos();
		}
	}
}
