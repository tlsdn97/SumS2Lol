#pragma once
class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	vector<HPEN>		_pens;
	vector<HBRUSH>		_brushes;

	shared_ptr<RectCollider> _rect;
	shared_ptr<CircleCollider> _circle;
};

