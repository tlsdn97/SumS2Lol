#include <iostream>
#include <unordered_map>>

using namespace std;

// ���������� : � ������ �ذ��ϱ� ���ؼ� ����� ����ؼ� ������ ����
// �̱���
// - �� �ϳ��� �����ؾ��Ѵ�.
// - �������� �����ؾߵȴ�.
// - �����ֱ⵵ ������ �� �־���Ѵ�.

class SoundManager
{
public:
	static void Create()
	{
		instance = new SoundManager();
	}

	static void Delete()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

	static SoundManager* Instance()
	{
		if (instance != nullptr)
		{
			return instance;
				return nullptr;
		}
	}

	void AttackSound() { cout << "Attack !" << endl; }
	void PlaySound(string key) { cout << _soundMap[key] << endl; }

private:
	SoundManager();
	static SoundManager* instance;

	unordered_map<string, string> _soundMap;
};

SoundManager* SoundManager::instance = nullptr;

int main()
{
	SoundManager::Create();
	
	SoundManager::Instance()->AttackSound();

	return 0;
}