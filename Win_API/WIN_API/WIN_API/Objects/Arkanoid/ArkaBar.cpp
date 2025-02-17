#include "framework.h"
#include "ArkaBar.h"

#include "ArkaBall.h"

ArkaBar::ArkaBar()
{
	_pos = CENTER + Vector(0, 200);
	_body = make_shared<RectCollider>(_pos, Vector(140, 20));
}

ArkaBar::~ArkaBar()
{
}

void ArkaBar::Init()
{
	for (int i = 0; i < 2; i++)
	{
		auto ball = make_shared<ArkaBall>(shared_from_this());
		ball->_isActive = false;
		ball->_isFired = false;


		_balls.push_back(ball);
	}
	_balls[0]->_isActive = true;
}

void ArkaBar::Update()
{
	_body->Update();
	
	for (auto ball : _balls)
	{
		ball->Update();
	}
}

void ArkaBar::Render(HDC hdc)
{
	_body->Render(hdc);
	for (auto ball : _balls)
	{
		ball->Render(hdc);
	}
}

void ArkaBar::Input()
{
	_delayTime += 0.1f;

	if (GetKeyState('A') & 0X8000)
	{
		_pos += Vector(-1, 0) * 10;
	}
	if (GetKeyState('D') & 0X8000)
	{
		_pos += Vector(1, 0) * 10;
	}
	
	_body->SetCenter(_pos);

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (_delayTime > 3.0f)
		{
			_delayTime = 0.0f;

			auto ballIter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<ArkaBall> a) -> bool
				{
					if (a->IsActive())
						return false;
					return true;
				});
			if (ballIter != _balls.end())
				(*ballIter)->Fire(Vector(0, -1));
		}
	}
}

