#include "framework.h"
#include "Brick.h"

Brick::Brick()
{
	_body = make_shared<RectCollider>(CENTER, Vector(100, 40));
}

Brick::~Brick()
{
}

void Brick::Update()
{
	if (!_isActive)
		return;


	_body->Update();
	_body->SetCenter(_pos);
}

void Brick::Render(HDC hdc)
{
	_body->Render(hdc);
}
