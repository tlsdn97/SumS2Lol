#pragma once
class ArkaMap;

class Brick
{
	friend ArkaMap;
public:
	Brick();
	~Brick();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { pos = _pos; }
	Vector GetPos() { return _pos; }
	shared_ptr<RectCollider> GetCollider() { return _body; }
private:
	bool _isActive = false;

	shared_ptr<RectCollider> _body;
	Vector _pos;
};

