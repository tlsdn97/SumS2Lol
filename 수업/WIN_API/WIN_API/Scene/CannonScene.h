#pragma once

class Cannon;

class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<Cannon> _cannon;
	shared_ptr<Cannon> _cannon2;
};

