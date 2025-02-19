#pragma once

<<<<<<< HEAD
class Bar;
class ArkaBall;
class Brick;
=======
class ArkaBrick;
class ArkaBall;
class ArkaBar;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
class ArkaMap;

class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();
<<<<<<< HEAD
	
=======

>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<ArkaMap> _map;
<<<<<<< HEAD
	shared_ptr<Bar> _bar;
	shared_ptr<ArkaBall> _ball;
	shared_ptr<Brick> _brick;
=======
	shared_ptr<ArkaBar> _bar;

	shared_ptr<class Hp> _ui;
>>>>>>> db6d49e58888e580d27ef5ee2d6378544e5952c3
};

