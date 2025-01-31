#pragma once

class Cannon;

class CannonScene : public Scene
{
public:
	enum CannonTurn
	{
		ONE ,
		TWO ,

		TURN_COUNT
	};

	CannonScene();
	~CannonScene();

	// cannon들이 Fire햇을 때 이 함수를 호출
	void NextTurn()
	{
		int temp = static_cast<int>(_curTurn);
		temp++;
		temp %= CannonTurn::TURN_COUNT;
		_curTurn = static_cast<CannonTurn>(temp);

		_timeElipse = 0.0f;
	}

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;

private:
	float _delay = 1.0f;
	float _timeElipse = 0.0f;

	shared_ptr<Cannon> _cannon;
	shared_ptr<Cannon> _cannon2;

	CannonTurn _curTurn = CannonScene::ONE;
};

