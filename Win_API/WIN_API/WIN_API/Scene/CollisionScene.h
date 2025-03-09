#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<Collider> _circle;
	shared_ptr<Collider> _movingCircle;

	// rect�� movingRect �߰�
	shared_ptr<Collider> _rect;
	shared_ptr<Collider> _movingRect;
};

