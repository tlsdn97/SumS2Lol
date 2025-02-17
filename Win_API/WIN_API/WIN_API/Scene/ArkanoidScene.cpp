#include "framework.h"
#include "ArkanoidScene.h"

#include "Objects/Arkanoid/ArkaBall.h"
#include "Objects/Arkanoid/ArkaBar.h"
#include "Objects/Arkanoid/ArkaBrick.h"
#include "Objects/Arkanoid/ArkaMap.h"
#include "Objects/Arkanoid/Hp.h"

ArkanoidScene::ArkanoidScene()
{
	_bar = make_shared<ArkaBar>();
	_map = make_shared<ArkaMap>();

	_bar->Init();

	_ui = make_shared<Hp>(CENTER + Vector(-450, -360), Vector(350, 20));

	_ui->SetValue(0.5);
	
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_bar->Update();
	_map->Update();
	_ui->Update();

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

	_ui->Render(hdc);
}
