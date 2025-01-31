#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _circle->SetCenter(pos); }
	void AddForce(Vector v);

	void SetActive(bool value) { _ballSpeed = 0.0f; isActive = value; }

	bool IsActive() { return isActive; }

	shared_ptr<Collider> GetCollider() { return _circle; }

	bool isActive = false;

private:
	shared_ptr<CircleCollider>  _circle;
	Vector _dir = Vector(1, 0);
	float _speed = 2.0f;



	float _ballSpeed = 2.0f;
	const float _V = 0.6;
};

