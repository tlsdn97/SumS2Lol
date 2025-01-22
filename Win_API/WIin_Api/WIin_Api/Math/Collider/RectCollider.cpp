#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	: _center(center), _halfSize(size * 0.5f)
{
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
}

RectCollider::~RectCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);

	float left = _center.x - _halfSize.x;
	float right = _center.x + _halfSize.x;
	float top = _center.y - _halfSize.y;
	float bottom = _center.y + _halfSize.y;

	Rectangle(hdc, left, top, right, bottom);
}


// Rect 회전하지않는다는 조건
bool RectCollider::IsCollision(const Vector& pos)
{
	// x값만 봤을 때 사이에 있다.
	if (pos.x > Left() && pos.x < Right())
	{
		// y값만 봤을 때 사이에 있다.
		if (pos.y > Top() && pos.y < Bottom())
		{
			return true;
		}
	}

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	if (other->Left() > Right())
		return false;
	if (other->Right() < Left())
		return false;
	if (other->Top() > Bottom())
		return false;
	if (other->Bottom() < Top())
		return false;

	return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector circleCenter = other->GetCenter();
	float radius = other->Radius();
	float length = (circleCenter - _center).Length();

	if (circleCenter.x < Right() && circleCenter.x > Left())
	{
		float result = 0.0f;
		if (circleCenter.y > _center.y)
			result = circleCenter.y - _center.y;
		else
			result = _center.y - circleCenter.y;

		return result < radius + _halfSize.y;
	}

		if (circleCenter.y < Bottom() && circleCenter.y > Top())
		{
			float result = 0.0f;
			if (circleCenter.x > _center.x) 
				result = circleCenter.x - _center.x;
			else
				result = _center.x - circleCenter.x;

			return result < radius + _halfSize.x;
		}

		Vector leftTop = Vector(Left(), Top());
		Vector rightTop = Vector(Right(), Top());
		Vector leftBottom = Vector(Left(), Bottom());
		Vector rightBottom = Vector(Right(), Bottom());

		bool check1 = other->IsCollision(leftTop);
		bool check2 = other->IsCollision(rightTop);
		bool check3 = other->IsCollision(leftBottom);
		bool check4 = other->IsCollision(rightBottom);

		return check1 || check2 || check3 || check4;
}