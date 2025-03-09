#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
: Collider(center), _halfSize(size * 0.5f)
{
	_type = ColType::RECT;
}

RectCollider::~RectCollider()
{
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


// Rect ȸ�������ʴ´ٴ� ����
bool RectCollider::IsCollision(const Vector& pos)
{
	// x���� ���� �� ���̿� �ִ�.
	if (pos.x > Left() && pos.x < Right())
	{
		// y���� ���� �� ���̿� �ִ�.
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
	Vector dir = other->GetCenter() - GetCenter();
	Vector rightV = Vector(1, 0);
	Vector upV = Vector(0, - 1);

	// ����ó��
	float length = dir.Length();
	float rectHalfLength = _halfSize.Length();
	float circleRadius = other->GetRadius();

	if (length > rectHalfLength + circleRadius)
		return false;

	// x�� ����
	float lengthX = abs(rightV.Dot(dir));
	if (lengthX > _halfSize.x + circleRadius)
		return false;

	// y�� ����
	float lengthY = abs(upV.Dot(dir));
	if (lengthY > _halfSize.y + circleRadius)
		return false;

	return true;
}