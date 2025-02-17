#pragma once
class Hp
{
public:
	Hp(Vector center, Vector size);
	~Hp();

	void Update();
	void Render(HDC hdc);
	void SetValue(float value);

private:
	shared_ptr<RectCollider> _bg;
	shared_ptr<RectCollider> _value;

	HBRUSH _redBrush;
	HBRUSH _oldBrush;
};

