#pragma once
<<<<<<< HEAD
class Bar;
=======
class ArkaBar;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

class ArkaBall
{
public:
<<<<<<< HEAD
	ArkaBall(shared_ptr<Bar> bar);
=======
	friend class ArkaBar;

	ArkaBall(shared_ptr<ArkaBar> bar);
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
	~ArkaBall();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _pos = pos; }
<<<<<<< HEAD
	Vector Getpos() { return _pos; }
=======
	Vector GetPos() { return _pos; }
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3

	void Fixed();
	void Fire(Vector dir);

	void Reflection_Wall();

	void SetDir(Vector dir) { _dir = dir.NormalVector(); }
	Vector GetDir() { return _dir; }

<<<<<<< HEAD
=======
	shared_ptr<CircleCollider> GetCollider() { return _circle; }

	bool IsFired() { return _isFired; }
	bool& IsActive() { return _isActive; }

>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
private:
	shared_ptr<CircleCollider> _circle;

	Vector _pos = { 0,0 };
	Vector _dir = { 0,0 };
	float _speed = 7.0f;

<<<<<<< HEAD
	weak_ptr<Bar> _bar;

	bool _isFired = false;
=======
	weak_ptr<ArkaBar> _bar;

	bool _isFired = false;
	bool _isActive = false;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
};

