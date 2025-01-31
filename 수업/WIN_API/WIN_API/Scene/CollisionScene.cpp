#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle = make_shared<CircleCollider>(Vector(450, 500), 100);
	_movingCircle = make_shared<CircleCollider>(Vector(0, 0), 60);

	// rect, moving ����
	_rect = make_shared<RectCollider>(Vector(800, 500), Vector(130, 50));
	_movingRect = make_shared<RectCollider>(Vector(0, 0), Vector(15, 70));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	//_movingCircle->SetCenter(mousePos);
	// movingRect �����̱�
	_movingRect->SetCenter(mousePos);

	// circle�� movingrect �浹�����ؼ� ���ٲٱ�
	if (_movingRect->IsCollision(_circle))
	{
		_circle->SetRed();
	}
	else
	{
		_circle->SetGreen();
	}


	//if (_circle->IsCollision(_movingCircle))
	//{
	//	_circle->SetRed();
	//}
	//else
	//{
	//	_circle->SetGreen();
	//}

	_circle->Update();
	_movingCircle->Update();

	_rect->Update();
	_movingRect->Update();
}

void CollisionScene::Render(HDC hdc)
{
	_circle->Render(hdc);
	_movingCircle->Render(hdc);

	_rect->Render(hdc);
	_movingRect->Render(hdc);
}
