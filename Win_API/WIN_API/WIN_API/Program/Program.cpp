#include "framework.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/LineScene.h"
#include "Scene/LineCollisionScene.h"
#include "Scene/CannonScene.h"
#include "Scene/ArkanoidScene.h"
<<<<<<< HEAD
=======
#include "Scene/MazeScene.h"
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3


HDC Program::backbuffer = nullptr;
Program::Program()
{
	_scene = make_shared<ArkanoidScene>();
<<<<<<< HEAD
=======

	HDC hdc = GetDC(hWnd);

	backbuffer = CreateCompatibleDC(hdc);
	_hBitMap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT); // 그림을 그릴 도화지
	SelectObject(backbuffer, _hBitMap);
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
}

Program::~Program()
{
	DeleteObject(backbuffer);
	DeleteObject(_hBitMap);
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(backbuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);

	_scene->Render(backbuffer);

	// 복사
	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT,
		backbuffer, 0, 0, SRCCOPY);
}
