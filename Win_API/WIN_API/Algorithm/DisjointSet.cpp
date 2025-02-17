#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct User
{
	int guildId = 0;

	// hp...
};

class NaiveDisJointSet;

void GuildSystem()
{
	vector<User> users;

	for (int i = 0; i < 1000; i++)
	{
		users.push_back({ i });
	}

	// 555�� ° ������ , 1�� ° ���� ��忡 ����
	users[555].guildId = users[1].guildId;

	// usrs[1]�� ��� 3���� ����.
	// users[1].guildId = 3

	// guild ID�� 2�� �������� 1��忡 ���� => N��ŭ�� �ð����⵵
	for (auto& user : users)
	{
		if (user.guildId == 2)
		{
			user.guildId = 1;
		}
	}

	NaiveDisJointSet set(1000);

	// 555�� ° ������ , 1�� ° ���� ��忡 ����
	set.Merge(555, 1);

	set.Merge(2, 1);
}

class NaiveDisJointSet
{
public:
	NaiveDisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}


	// [0] [1] [2] [3] [4] [5]

	// => 5�� 0�� ���Ϸ� ����.
	// => 3�� 5���Ϸ� ����.
	//   [0] [1] [2] [4]
	// [5][3] 
	// 

	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];

		return FindLeader(parent);
	}

	// [0] [1]  [4]
	// [5] [2]
	// [3]

	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		// ���� ��� �Ҽ��̳�?
		if (uLeader == vLeader)
			return;

		_parent[uLeader] = vLeader;
	}

private:
	vector<int> _parent;
};

class DisJointSet
{
public:
	DisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}

		_rank = vector<int>(n, 1);
	}

	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];

		return FindLeader(parent);
	}


	//			        3
	//			       [3]  
	//			       [2]  [0]
	//               [4]  [5] [1]
	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
			std::swap(uLeader, vLeader);

		// vLeader�� ��ũ�� �׻� ũ�ų� ����.
		_parent[uLeader] = vLeader;

		// ���� ��ũ�� �������� vLeader�� ũ�� 1����.
		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{
	GuildSystem();

	return 0;
}