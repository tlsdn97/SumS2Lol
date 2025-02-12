#include "framework.h"
#include "ArkaBrick.h"
#include "ArkaItem.h"

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

void ArkaBrick::SetItem(shared_ptr<ArkaItem> item)
{
	_item = item;
	if (_item.expired())
		return;

	_item.lock()->Pos() = _pos;
}

void ArkaBrick::Break_Brick()
{
	_isActive = false;
	if (!_item.expired())
		_item.lock()->CanFalling() = true;
}
