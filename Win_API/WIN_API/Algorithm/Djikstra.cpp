#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


vector<vector<int>> adjacent;
vector<int> parent; // => �ִܰŸ�
vector<int> best;

struct Vertex
{
	Vertex() {}
	Vertex(int vertexNum, int cost) : vertexNum(vertexNum), cost(cost) {}

	bool operator<(const Vertex& v) const
	{
		if (cost < v.cost)
			return true;
		return false;
	}

	bool operator>(const Vertex& v) const
	{
		if (cost > v.cost)
			return true;
		return false;
	}

	int vertexNum = 0;
	int cost = 0; // ������������ ����ġ
};

void CreateGraph()
{
	adjacent = vector<vector<int>>(7, vector<int>(7, -1));
	parent = vector<int>(7, -1);

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

// BFS���� ����ġ�� �߰��� ����
void Djikstra(int start)
{
	best = vector<int>(adjacent.size(), INT_MAX);
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

	Vertex startV = Vertex(start, 0);
	best[start] = 0;
	parent[start] = start;
	pq.push(startV);

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		int here = hereV.vertexNum;
		pq.pop();

		// pq�� ����ɸ� Vertex�� �����µ� �� ���� ��θ� �̹� �߰��ߴ�.
		if (best[here] < hereV.cost)
		{
			cout << "�� ���� ��ΰ� ������ �߰߉�!!" << endl;
			cout << here << endl;
			cout << hereV.cost << endl;
			cout << best[here] << endl;

			continue;
		}

		for (int there = 0; there < adjacent.size(); there++)
		{
			if (here == there)
				continue;

			if (adjacent[here][there] == -1)
				continue;

			int thereCost = hereV.cost + adjacent[here][there];

			// ���� �߰��� ���� best�� �� �۾Ҵ�? => pq������ ���� �ʰڴ�.
			if (thereCost >= best[there])
				continue;

			Vertex thereV(there, thereCost);
			pq.push(thereV);
			best[there] = thereCost;
			parent[there] = here;
		}
	}
}

int main()
{
	CreateGraph();
	Djikstra(0);

	int vertex = 6;
	cout << vertex << endl;
	while (true)
	{
		if (vertex == parent[vertex])
			break;

		vertex = parent[vertex];
		cout << vertex << endl;
	}

	return 0;
}