#pragma once

class ArkaBrick;
class ArkaBall;
class ArkaBar;
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
	shared_ptr<ArkaBar> _bar;

	shared_ptr<class Hp> _ui;
};

