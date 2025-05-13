#include "framework.h"

using namespace std;

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
		READ_LOCK;

		// ���̵� ����

		return nullptr;
	}

	void Save();
public:
	USE_LOCK;
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
		READ_LOCK;

		// ���� ������ ����´�...

		return nullptr;
	}

	void Login();

public:
	USE_LOCK;
	static AccountManager* _instance;
};
AccountManager* AccountManager::_instance = nullptr;

void UserManager::Save()
{
	WRITE_LOCK;
	// ���¸� Ȯ���ϰ� ����
	Account* account = AccountManager::GetInstance()->GetAccount(10);

	// ���� ����
	// DB�� Update

	return;
}

void AccountManager::Login()
{
	WRITE_LOCK;

	User* user = UserManager::GetInstance()->GetUser(10);

	// User ������ Ȯ���ϰ� ���� �ÿ� ���
	// DB���� Ȯ��

	return;
}

void Login()
{
	for (int i = 0; i < 10000; i++)
		AccountManager::GetInstance()->Login();

}

void Save()
{
	for (int i = 0; i < 10000; i++)
		UserManager::GetInstance()->Save();
}

int main()
{
	TM->Create();

	AccountManager::Create();
	UserManager::Create();

	TM->Launch(Login);
	TM->Launch(Save);

	TM->Join();

	AccountManager::Delete();
	UserManager::Delete();

	TM->Delete();

	return 0;
}
