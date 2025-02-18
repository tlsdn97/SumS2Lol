#include "framework.h"
#include "ArkaBrick.h"


ArkaBrick::ArkaBrick(Vector size)
{
	_pos = CENTER;
	_body = make_shared<RectCollider>(CENTER, size);
}

ArkaBrick::~ArkaBrick()
{
}

void ArkaBrick::Update()
{
	if (!_isActive)
		return;

	_body->Update();

	_body->SetCenter(_pos);
}

void ArkaBrick::Render(HDC hdc)
{
	if (_isActive)
		_body->Render(hdc);
}

void ArkaBrick::Break_Brick()
{
	if (!_isActive)
		return;
}


