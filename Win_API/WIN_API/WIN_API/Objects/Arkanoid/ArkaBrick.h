#pragma once

class ArkaMap;


class ArkaBrick
{
	friend class ArkaMap;
public:
	ArkaBrick(Vector size);
	~ArkaBrick();
	
	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }

	shared_ptr<RectCollider> GetCollider() { return _body; }

	void Break_Brick();

private:
	bool _isActive = false;

	shared_ptr<RectCollider> _body;
	Vector _pos;

};

