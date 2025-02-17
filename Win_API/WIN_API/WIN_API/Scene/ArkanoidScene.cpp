#include "framework.h"
#include "ArkanoidScene.h"

#include "Objects/Arkanoid/ArkaBall.h"
#include "Objects/Arkanoid/ArkaBar.h"
#include "Objects/Arkanoid/ArkaBrick.h"
#include "Objects/Arkanoid/ArkaMap.h"

ArkanoidScene::ArkanoidScene()
{
	_bar = make_shared<ArkaBar>();
	_map = make_shared<ArkaMap>();

	_bar->Init();
	
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_bar->Update();
	_map->Update();

	_bar->Input();
	
	for (auto ball : _bar->GetBalls())
	{
		if (ball->IsFired() == false)
			continue;
		_map->IsCollision_Bricks(ball);
	}
	
}

void ArkanoidScene::Render(HDC hdc)
{
	_bar->Render(hdc);
	_map->Render(hdc);
}
