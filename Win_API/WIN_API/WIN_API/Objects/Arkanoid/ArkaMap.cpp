#include "framework.h"
#include "ArkaMap.h"

#include "ArkaBall.h"
#include "ArkaBar.h"
#include "ArkaBrick.h"
#include "ArkaItem.h"

ArkaMap::ArkaMap()
{
	_bricks.resize(_countY);

	Vector offset;
	int x = ((_brickSize.x + _brickGap.x) * _countX) / 2.0f;

	Vector temp = CENTER;
	offset.x = temp.x - x;
	offset.y = 200.0f;

	for (int y = 0; y < _countY; y++)
	{
		for (int x = 0; x < _countX; x++)
		{
			shared_ptr<ArkaBrick> brick = make_shared<ArkaBrick>(_brickSize);

			Vector brickPos;
			brickPos.x = (_brickSize.x + _brickGap.x) * x;
			brickPos.y = (_brickSize.y + _brickGap.y) * y;

			brick->SetPos(brickPos + offset);
			brick->_isActive = true;
			_bricks[y].push_back(brick);
		}
	}
}

ArkaMap::~ArkaMap()
{
}

void ArkaMap::Init(shared_ptr<ArkaBar> bar)
{
	shared_ptr<ArkaItem> item = make_shared<ArkaItem>();
	item->SetSkill(std::bind(&ArkaBar::TwoBall_Skill, bar));
	_items.push_back(item);
	_bricks[0][0]->SetItem(item);
}

void ArkaMap::Update()
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			brick->Update();
		}
	}

	for (auto item : _items)
		item->Update();
}

void ArkaMap::Render(HDC hdc)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			brick->Render(hdc);
		}
	}
	
	for (auto item : _items)
		item->Render(hdc);
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

void ArkaMap::GetItems(shared_ptr<ArkaBar> bar)
{
	for (auto item : _items)
	{
		if (item->GetCollider()->IsCollision(bar->GetCollider()))
		{
			item->ActiveSkill();
		}
	}
}
