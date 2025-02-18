#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;


	virtual bool IsCollision(const Vector& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) override;

	Vector GetHalfSize() { return _halfSize; }

	int Left() { return center.x - _halfSize.x; }
	int Right() { return center.x + _halfSize.x; }
	int Top() { return center.y - _halfSize.y; }
	int Bottom() { return center.y + _halfSize.y; }

private:

	Vector					_halfSize;
};

