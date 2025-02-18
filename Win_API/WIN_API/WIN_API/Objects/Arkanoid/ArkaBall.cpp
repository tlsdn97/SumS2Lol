#include "framework.h"
#include "ArkaBall.h"
<<<<<<< HEAD
#include "Bar.h"

ArkaBall::ArkaBall(shared_ptr<Bar> bar)
{
	_circle = make_shared<CircleCollider>(Vector(0,0), 10.0f);
=======
#include "ArkaBar.h"

ArkaBall::ArkaBall(shared_ptr<ArkaBar> bar)
{
	_circle = make_shared<CircleCollider>(Vector(0, 0), 15.0f);
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

	_bar = bar;
}

ArkaBall::~ArkaBall()
{
<<<<<<< HEAD
=======
	
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}

void ArkaBall::Update()
{
<<<<<<< HEAD
=======
	if (_isActive == false)
		return;             
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
	_circle->Update();

	_pos += _dir * _speed;
	_circle->SetCenter(_pos);

	Fixed();
<<<<<<< HEAD
=======
	Reflection_Wall();
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}

void ArkaBall::Render(HDC hdc)
{
<<<<<<< HEAD
=======
	if (_isActive == false)
		return;

	_circle->Render(hdc);
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}

void ArkaBall::Fixed()
{
	if (_bar.expired() || _isFired == true)
		return;
<<<<<<< HEAD
	shared_ptr<Bar> curBar = _bar.lock();
=======

	shared_ptr<ArkaBar> curBar = _bar.lock();
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
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
<<<<<<< HEAD

=======
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
	if (_pos.x < 0 || _pos.x > WIN_WIDTH)
		_dir.x *= -1;
	if (_pos.y < 0)
		_dir.y *= -1;
<<<<<<< HEAD

=======
	if (_pos.y > WIN_HEIGHT)
		_isActive = false;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
	if (_circle->IsCollision(_bar.lock()->GetCollider()))
	{
		Vector dir = _pos - _bar.lock()->GetPos();

		_dir = dir.NormalVector();
	}
}
