#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;

//  - DeadLock : ��������
//    mutex�� 2�� �ִ� ��Ȳ

// - SpinLock
//    : CAS
// - SleepLock
// - EventLock
//    : CV

class AccountManager;

class User {};
class Account {};

class UserManager
{
private:
	UserManager() {}
	~UserManager() {}

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new UserManager();
	}
	static void Delete()
	{
		if (_instance)
			delete _instance;
	}
	static UserManager* GetInstance() { return _instance; }

	User* GetUser(int id)
	{
		lock_guard<std::mutex> lg(_mutex);

		// ���̵� ����

		return nullptr;
	}

	void Save();

public:
	std::mutex _mutex;
	static UserManager* _instance;
};
UserManager* UserManager::_instance = nullptr;

class AccountManager
{
private:
	AccountManager() {}
	~AccountManager() {}

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new AccountManager();
	}
	static void Delete()
	{
		if (_instance)
			delete _instance;
	}
	static AccountManager* GetInstance() { return _instance; }
	Account* GetAccount(int id)
	{
		lock_guard<std::mutex> lg(_mutex);

		// ���� ������ ����´�...

		return nullptr;
	}

	void Login();

public:
	std::mutex _mutex;
	static AccountManager* _instance;
};
AccountManager* AccountManager::_instance = nullptr;

int main()
{
	AccountManager::Create();
	UserManager::Create();

	std::thread t1([]()->void
		{
			for (int i = 0; i < 10000; i++)
			{
				AccountManager::GetInstance()->Login();
			}
		});

	std::thread t2([]()->void
		{
			for (int i = 0; i < 10000; i++)
			{
				UserManager::GetInstance()->Save();
			}
		});

	t1.join();
	t2.join();

	return 0;
}

void UserManager::Save()
{
	lock_guard<std::mutex> lg(_mutex);

	// ���¸� Ȯ���ϰ� ����
	Account* account = AccountManager::GetInstance()->GetAccount(10);

	// ���� ����
	// DB�� Update

	return;
}

void AccountManager::Login()
{
	lock_guard<std::mutex> lg(_mutex);

	User* user = UserManager::GetInstance()->GetUser(10);

	// User ������ Ȯ���ϰ� ���� �ÿ� ���
	// DB���� Ȯ��

	return;
}