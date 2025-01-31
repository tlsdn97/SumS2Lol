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

//  Vector center = _circle->center;
//  if (center.x > WIN_WIDTH || center.x < 0)
//  {
// 	 _dir.x *= -1;
//  }
//  
//  if (center.y > WIN_WIDTH || center.y < 0)
//  {
// 	 _dir.y *= -1;
//  }
//  
//  _circle->center += _dir * _speed;
 
	_circle->center.y += _ballSpeed;
	_ballSpeed += _V;

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
