#include "framework.h"
#include "ArkaItem.h"

ArkaItem::ArkaItem()
{
	_body = make_shared<CircleCollider>(_pos, 5.0f);
}

ArkaItem::~ArkaItem()
{
}

void ArkaItem::Update()
{
	_body->Update();
	_body->SetCenter(_pos);

	if (_canFalling)
		_pos += _dir * _speed;
}

void ArkaItem::Render(HDC hdc)
{
	_body->Render(hdc);
}
