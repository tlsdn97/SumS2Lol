#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

// unordered_map : �ؽ� ���̺�
// �ؽ� : 
// ü�̴� : 
// Key - Value�� �����ε� ���ҷ� �̷���� ǥ
// => �ؽ��� �̿��ؼ� Ž���ð��� '���' , ����, ���� (���)
// ==> Key������ Ž���� �����ϴ�.
// ===> ����, ��Ŭ����Ƽ�� �ε���

// map : �ڰ���������Ž��Ʈ��, �����Ʈ��
// Key - Value�� �����ε� ���ҷ� �̷���� ����Ž��Ʈ��
// => ����Ž���� Ȱ���Ͽ� Ž��,����,���� �ð��� 'logN'
// ==> Key������ Ž���� �����ϴ�.
// ===> Database, �⺻key

class Player
{
public:
	Player() {}
	Player(int id) : _id(id) {}

public:
	int _id;
};

int main()
{
	// vector�� Ž���ϴ� ��� �ð����⵵(N)�� �ɸ���.

	map<int, Player> m;

	m.erase(1); // logN

	for (int i = 0; i < 1000; i++)
	{
		m[i + 1] = Player(i);
		//pair<int, Player> pair = make_pair<int, Player>(i + 1, Player(i));
		//auto result = um.insert(pair);
	}

	map<int, Player>::iterator m_iter;

	for (m_iter = m.begin(); m_iter != m.end(); m_iter++)
	{
		pair<int, Player> p = *m_iter;
		cout << "Key : " << p.first << endl;
	}

	return 0;
}