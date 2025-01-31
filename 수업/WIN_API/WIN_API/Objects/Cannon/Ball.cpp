#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(Vector(-1000, -1000), 10);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (isActive == false) return;

	_circle->Update();

	if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x < 0
		|| _circle->GetCenter().y > WIN_HEIGHT || _circle->GetCenter().y < 0)
	{
		isActive = false;
	}
}

void Ball::Render(HDC hdc)
{
	if (isActive == false) return;

	_circle->Render(hdc);
}

void Ball::AddForce(Vector v)
{
	if (isActive == false) return;

	_circle->SetCenter(_circle->GetCenter() + v);
}
