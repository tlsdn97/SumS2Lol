#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size);
	virtual ~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual bool IsCollision(const Vector& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) override;

<<<<<<< HEAD
	Vector GetHalfSize() { return _halfSize; }

	int Left() { return center.x - _halfSize.x; }
	int Right() { return center.x + _halfSize.x; }
	int Top() { return center.y - _halfSize.y; }
	int Bottom() { return center.y + _halfSize.y; }
=======
	int Left() { return _center.x - _halfSize.x; }
	int Right() { return _center.x + _halfSize.x; }
	int Top() { return _center.y - _halfSize.y; }
	int Bottom() { return _center.y + _halfSize.y; }

	Vector GetHalfSize() { return _halfSize; }
	void SetSize(Vector size) { _halfSize = size * 0.5f; }
	Vector GetSize() { return _halfSize * 2.0f; }
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

private:
	Vector					_halfSize;
};

