#pragma once

#include"Scene/CannonScene.h"

class Barrel;
class Ball;

class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	// �ñ״��� ��ȯ�ڷ��� (void), �Ű�����(void)��  callable ��ü�� ���� �� �ִ� �Ű����� ����
	// Callable ��ü> => �����̸�()
	void Fire(function<void(void)> fn);
	bool IsCollision(shared_ptr<Ball> ball);
	vector <shared_ptr<Ball>> GetBalls() { return _balls; }

	shared_ptr<CircleCollider> GetCollider() { return _body; }

private:


	shared_ptr<CircleCollider>	_body;
	
	float _delay = 0.0f;
	const float _attackSpeed = 3.0f;


	shared_ptr<Barrel>			_barrel;

	
	UINT						_poolCount;
	vector<shared_ptr<Ball>>	_balls;

	float _speed;
	bool _isActive = true;
};

