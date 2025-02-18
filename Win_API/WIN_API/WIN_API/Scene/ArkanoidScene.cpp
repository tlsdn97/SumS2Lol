#include "framework.h"
#include "ArkanoidScene.h"

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
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_bar->Update();
	_ball->Update();
	_brick->Update();
	_map->Update();

	_bar->Input(_ball);
}

void ArkanoidScene::Render(HDC hdc)
{
	_bar->Render(hdc);
	_ball->Render(hdc);
	_brick->Render(hdc);
	_map->Render(hdc);
}
