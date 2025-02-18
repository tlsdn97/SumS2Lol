#pragma once

class Bar;
class ArkaBall;
class Brick;
class ArkaMap;

class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();
	
	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<ArkaMap> _map;
	shared_ptr<Bar> _bar;
	shared_ptr<ArkaBall> _ball;
	shared_ptr<Brick> _brick;
};

