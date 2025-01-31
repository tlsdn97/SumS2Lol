#include <iostream>

using namespace std;

// ���� �Ŵ���
// 1. ���α׷� ������ �� �Ѱ�
// 2. �������� ���带 ����, ��𼭵� ��µ� �����ؾ߉�.
// 3. ���� ������ ����ڰ� ������ �� �־����.

class SoundManager
{
public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new SoundManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static SoundManager* GetInstance()
	{
		return _instance;
	}

	void AttackSound() { cout << _attackSound << endl; }

private:
	SoundManager() : _attackSound("Attack!!!") {}
	~SoundManager() {}

private:
	static SoundManager* _instance;

	string _attackSound;
};

SoundManager* SoundManager::_instance = nullptr;

int main()
{
	SoundManager::Create();

	SoundManager::GetInstance()->AttackSound();

	SoundManager::Delete();

	return 0;
}