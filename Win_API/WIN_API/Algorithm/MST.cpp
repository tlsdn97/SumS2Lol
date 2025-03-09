#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

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

vector<vector<int>> adjacent;
vector<class Edge> edges;

void CreateGraph()
{
	adjacent = vector<vector<int>>(7, vector<int>(7, -1));

	adjacent[0][0] = 0;
	adjacent[0][1] = 1;
	adjacent[0][2] = 10;
	adjacent[0][3] = 5;

	adjacent[1][0] = 1;
	adjacent[1][1] = 0;
	adjacent[1][2] = 5;
	adjacent[1][4] = 5;

	adjacent[2][0] = 10;
	adjacent[2][1] = 5;
	adjacent[2][2] = 0;
	adjacent[2][5] = 3;
	adjacent[2][6] = 8;

	adjacent[3][0] = 5;
	adjacent[3][3] = 0;
	adjacent[3][6] = 10;

	adjacent[4][1] = 5;
	adjacent[4][4] = 0;

	adjacent[5][2] = 3;
	adjacent[5][5] = 0;

	adjacent[6][2] = 8;
	adjacent[6][3] = 10;
	adjacent[6][6] = 0;
}

// ���д�Ʈ��(Spanning Tree)
// - ��� ������ �湮�� �� �ִ� ������ ����
// - ����Ŭ�� �����ϸ� �ȵȴ�.
// - ������ ������ n�� ��, n-1���� ������ ���´�.

// �ּҽ��д�Ʈ��
// - ����ġ �׷������� ���д�Ʈ�� �߿� ���� ���� ����ġ�� ���� ��

struct Edge
{
	int u;
	int v;

	int cost;
};

void CreateEdges()
{
	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent.size(); v++)
		{
			if (adjacent[u][v] < 0)
				continue;

			if (u >= v)
				continue;

			Edge edge;
			edge.u = u;
			edge.v = v;
			edge.cost = adjacent[u][v];

			edges.push_back(edge);
		}
	}
}

vector<Edge> Kruskal()
{
	vector<Edge> result;

	// �ּ� �������� ã�� => ����
	std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)-> bool 
		{
			if (a.cost < b.cost)
				return true;
			return false;
		});

	DisJointSet set(adjacent.size());

	for (auto edge : edges)
	{
		int u = edge.u;
		int v = edge.v;

		// ���� ����?
		if (set.FindLeader(u) == set.FindLeader(v))
			continue;

		result.push_back(edge);
		set.Merge(u, v);
	}

	return result;
}

int main()
{
	CreateGraph();
	CreateEdges();
	auto mst = Kruskal();

	for (auto edge : mst)
	{
		cout << "U : " << edge.u << ", V : " << edge.v << ", Cost : " << edge.cost << endl;
	}

	return 0;
}