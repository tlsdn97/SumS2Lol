#include "framework.h"
#include "ArkanoidScene.h"

<<<<<<< HEAD
#include "Objects/Arkanoid/Bar.h"
#include "Objects/Arkanoid/ArkaBall.h"
#include "Objects/Arkanoid/Brick.h"
#include "Objects/Arkanoid/ArkaMap.h"


ArkanoidScene::ArkanoidScene()
{
	_bar = make_shared<Bar>();
	_ball = make_shared<ArkaBall>(_bar);
	_brick = make_shared<Brick>();
	_map = make_shared<ArkaMap>();
=======
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
	
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_bar->Update();
<<<<<<< HEAD
	_ball->Update();
	_brick->Update();
	_map->Update();

	_bar->Input(_ball);
=======
	_map->Update();
	_ui->Update();

	_bar->Input();
	
	for (auto ball : _bar->GetBalls())
	{
		if (ball->IsFired() == false)
			continue;
		_map->IsCollision_Bricks(ball);
	}
	
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}

void ArkanoidScene::Render(HDC hdc)
{
	_bar->Render(hdc);
<<<<<<< HEAD
	_ball->Render(hdc);
	_brick->Render(hdc);
	_map->Render(hdc);
=======
	_map->Render(hdc);

	_ui->Render(hdc);
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}
