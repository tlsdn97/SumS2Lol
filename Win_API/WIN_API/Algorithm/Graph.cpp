#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// �׷���
// Vertex�� edge�� �̷���� �ڷᱸ��

// => �׷����� ��ȸ ���
// DFS(Deep First Search), BFS(Breadth First Seartch)
//  ���� �켱 Ž��,           ���� �켱 Ž��

// adjacent : �������ִ�.

// ��������Ʈ
vector<vector<int>> adjacent_list;
void CreateGraph_list()
{
	adjacent_list.resize(7);
	adjacent_list[0] = { 0,1,2,3 };
	adjacent_list[1] = { 0,1,4 };
	adjacent_list[2] = { 0, 2, 5,6 };
	adjacent_list[3] = { 0,3 };
	adjacent_list[4] = { 1,4 };
	adjacent_list[5] = { 2,5 };
	adjacent_list[6] = { 2,6 };
}

vector<vector<bool>> adjacent; // �������
// - �����͸� ���� �Դ���, Ž���ϴµ� ����� �ð��� �ɸ���.
void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false)); // 7x7
	//adjacent.resize(7, vector<bool>(7,false))

	// ������� �׷��� A�� A�� ��ġ���(A)�� ���� ����.

	//   0  1  2  3  4  5  6
	// 0 1  1  1  1  0  0  0
	// 1 1  1  0  0  1  0  0
	// 2 1  0  1  0  0  1  1
	// 3 1  0  0  1  0  0  0
	// 4 0  1  0  0  1  0  0
	// 5 0  0  1  0  0  1  0
	// 6 0  0  1  0  0  0  1

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][3] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][4] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][5] = true;
	adjacent[2][6] = true;

	adjacent[3][0] = true;
	adjacent[3][3] = true;

	adjacent[4][1] = true;
	adjacent[4][4] = true;
	
	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][2] = true;
	adjacent[6][6] = true;
}

int main()
{
	CreateGraph_list();
	// 0�� 2�� ���� ������ �Ǿ��ֳ�?
	auto iter = std::find(adjacent_list[0].begin(), adjacent_list[0].end(), 2);

	if (iter != adjacent_list[0].end())
		cout << *iter << endl;

	CreateGraph();
	// 0�� 2�� ���� ����Ǿ��ֳ�?
	if (adjacent[0][2]) // ����� �ð�
	{
		cout << "0�� 2�� ����Ǿ��ֽ��ϴ�." << endl;
	}

	return 0;
}