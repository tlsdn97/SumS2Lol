#pragma once

class ArkaBall;

class ArkaBar : public enable_shared_from_this<ArkaBar>
{
public:
	ArkaBar();
	~ArkaBar();

	void Init();

	void Update();
	void Render(HDC hdc);

	void Input();

	Vector GetPos() { return _pos; }
	shared_ptr<RectCollider> GetCollider() { return _body; }
	vector<shared_ptr<ArkaBall>> GetBalls() { return _balls; }



private:
	float _delayTime = 0.0f;

	shared_ptr<RectCollider> _body;

	Vector _pos;

	vector<shared_ptr<ArkaBall>> _balls;
};

