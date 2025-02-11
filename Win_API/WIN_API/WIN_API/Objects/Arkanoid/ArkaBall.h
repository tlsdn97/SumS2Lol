#pragma once
class ArkaBar;

class ArkaBall
{
public:
	friend class ArkaBar;

	ArkaBall(shared_ptr<ArkaBar> bar);
	~ArkaBall();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }

	void Fixed();
	void Fire(Vector dir);

	void Reflection_Wall();

	void SetDir(Vector dir) { _dir = dir.NormalVector(); }
	Vector GetDir() { return _dir; }

	shared_ptr<CircleCollider> GetCollider() { return _circle; }

	bool IsFired() { return _isFired; }
	bool& IsActive() { return _isActive; }

private:
	shared_ptr<CircleCollider> _circle;

	Vector _pos = { 0,0 };
	Vector _dir = { 0,0 };
	float _speed = 5.0f;

	weak_ptr<ArkaBar> _bar;

	bool _isFired = false;
	bool _isActive = false;
};

