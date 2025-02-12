#pragma once

class Cannon;

class CannonScene : public Scene
{
public:
	enum CannonTurn
	{
		ONE,
		TWO,

		TURN_COUNT
	};

	CannonScene();
	~CannonScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;

	// Cannon���� Fire���� �� �� �Լ��� ȣ��
	void NextTurn()
	{
		int temp = static_cast<int>(_curTurn);
		temp++;
		temp %= CannonTurn::TURN_COUNT;
		_curTurn = static_cast<CannonTurn>(temp);

		_timeElipse = 0.0f;
	}

private:
	float _delay = 1.0f;
	float _timeElipse = 0.0f;

	shared_ptr<Cannon> _cannon;
	shared_ptr<Cannon> _cannon2;

	CannonTurn _curTurn = CannonTurn::ONE;
};

