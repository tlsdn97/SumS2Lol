#include "framework.h"
#include "ArkaBall.h"
#include "Bar.h"

ArkaBall::ArkaBall(shared_ptr<Bar> bar)
{
	_circle = make_shared<CircleCollider>(Vector(0,0), 10.0f);

	_bar = bar;
}

ArkaBall::~ArkaBall()
{
}

void ArkaBall::Update()
{
	_circle->Update();

	_pos += _dir * _speed;
	_circle->SetCenter(_pos);

	Fixed();
}

void ArkaBall::Render(HDC hdc)
{
}

void ArkaBall::Fixed()
{
	if (_bar.expired() || _isFired == true)
		return;
	shared_ptr<Bar> curBar = _bar.lock();
	Vector barPos = curBar->GetPos();
	Vector barHalf = curBar->GetCollider()->GetHalfSize();

	_pos = barPos + Vector(0, -barHalf.y);
}

void ArkaBall::Fire(Vector dir)
{
	_dir = dir.NormalVector();
	_isFired = true;
}

void ArkaBall::Reflection_Wall()
{
	if (!_isFired)
		return;

	if (_pos.x < 0 || _pos.x > WIN_WIDTH)
		_dir.x *= -1;
	if (_pos.y < 0)
		_dir.y *= -1;

	if (_circle->IsCollision(_bar.lock()->GetCollider()))
	{
		Vector dir = _pos - _bar.lock()->GetPos();

		_dir = dir.NormalVector();
	}
}
