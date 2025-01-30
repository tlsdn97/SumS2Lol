#include "framework.h"

#include "Objects/Cannon/Cannon.h"

#include "CannonScene.h"

CannonScene::CannonScene()
{
	_cannon = make_shared<Cannon>();
	_cannon->SetPos(Vector(300, 500));

	_cannon2 = make_shared<Cannon>();
	_cannon2->SetPos(Vector(700, 500));

	_cannon->Update();
	_cannon->Move();

	_cannon2->Update();
	_cannon2->Move();

}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	if (_turn)
	{
		_cannon->Fire();
		_cannon->Move();
	
	}
	else
	{
		_cannon2->Fire();
		_cannon2->Move();
		
	}



	_cannon->Update();
	_cannon2->Update();

	for (auto ball : _cannon->GetBalls())
	{
		_cannon2->IsCollision_Ball(ball);
	}
}

void CannonScene::Render(HDC hdc)
{
	_cannon->Render(hdc);
	_cannon2->Render(hdc);
}
