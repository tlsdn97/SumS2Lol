#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	: _center(center), _radius(radius)
{
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
}

CircleCollider::~CircleCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);

	float left = _center.x - _radius;
	float right = _center.x + _radius;
	float top = _center.y - _radius;
	float bottom = _center.y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(const Vector& pos)
{
	Vector circleCenter = GetCenter();
	Vector direction = pos - circleCenter;

	return direction.Length() < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector circleCenter_1 = GetCenter();
	Vector circleCenter_2 = other->GetCenter();
	Vector direction = (circleCenter_2 - circleCenter_1);

	return direction.Length() < _radius + other->_radius;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
   // float circleCenterX = this->_center.x;
   // float circleCenterY = this->_center.y;
   // float circleRadius = this->_radius;
   // 
   // float rectLeft = other->Left();
   // 
   // 
   //     float rectRight = other->Right();
   // float rectTop = other->Top();
   // 
   // 
   //     float rectBottom = other->Bottom();
   // 
   // 
   // float closestX = std::max(rectLeft, std::min(circleCenterX, rectRight));
   // float closestY = std::max(rectTop, std::min(circleCenterY, rectBottom));
   // 
   // 
   // float distanceX = circleCenterX - closestX;
   // float distanceY = circleCenterY - closestY;
   // 
   // 
   // float distanceSquared = distanceX * distanceX + distanceY * distanceY;
   // 
   // 
   // return distanceSquared <= (circleRadius * circleRadius);

	return false;
}
