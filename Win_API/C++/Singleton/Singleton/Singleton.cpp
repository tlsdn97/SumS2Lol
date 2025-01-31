#include <iostream>
#include <unordered_map>

using namespace std;

// ���������� : � ������ �ذ��ϱ� ���� ����� ����ؼ� ������ ����
// �̱���
// - �� �ϳ��� �����ؾ��Ѵ�.
// - �������� �����ؾߵȴ�.
// - �����ֱ⵵ ������ �� �־���Ѵ�.

class SoundManager
{
public:
	static void Create()
	{
		if(instance == nullptr)
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
			return instance;
		return nullptr;
	}
	
	void AttackSound() { cout << "Attack!!" << endl; }
	void PlaySound(string key) { cout << _soundMap[key] << endl; }

private:
	SoundManager() 
	{
		_soundMap["Attack"] = "Attack!! Sound!!";
		_soundMap["Dead"] = "Dead Sound!";
	}

	static SoundManager* instance;

	unordered_map<string, string> _soundMap;
};

SoundManager* SoundManager::instance = nullptr;


int main()
{
	SoundManager::Create();

	SoundManager::Instance()->PlaySound("Dead");

	SoundManager::Delete();

	return 0;
}