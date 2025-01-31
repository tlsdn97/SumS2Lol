#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<CircleCollider> _circle;
	shared_ptr<CircleCollider> _movingCircle;

	// rect�� movingRect �߰�
	shared_ptr<RectCollider> _rect;
	shared_ptr<RectCollider> _movingRect;
};

