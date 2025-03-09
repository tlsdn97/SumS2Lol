#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// Ʈ��
// 1. ������ ������ ��Ÿ���� �ڷᱸ��(�θ�� �ڽİ���)
// 2. Ʈ���� �߶� Ʈ����. (����Ʈ���� ����)
// => Ʈ���� ����� �Ӽ��� ���´�.

// Ʈ���� ����
// 1. ����Ʈ��
// 2. ��ȭ����Ʈ��
// 3. ��������Ʈ��
// 4. ��Ʈ�� (priority queue)
// 5. (�ڰ�����)����Ž��Ʈ�� (map, �����Ʈ��)

struct Node
{
	string data;

	vector<Node*> children;
};

Node* CreateTree()
{
	// C ��Ÿ��
	Node* root = new Node();
	root->data = "������";
	
	// ���α׷��� ��
	Node* programming = new Node();
	programming->data = "���α׷�����";
	root->children.push_back(programming);
	{
		Node* node1 = new Node();
		node1->data = "Ŭ���̾�Ʈ";
		programming->children.push_back(node1);

		Node* node2 = new Node();
		node2->data = "����";
		programming->children.push_back(node2);

		Node* node3 = new Node();
		node3->data = "����";
		programming->children.push_back(node3);
	}

	// ��ȹ ��
	Node* planing = new Node();
	planing->data = "��ȹ";
	root->children.push_back(planing);
	{
		Node* node1 = new Node();
		node1->data = "���丮";
		planing->children.push_back(node1);

		Node* node2 = new Node();
		node2->data = "����������";
		planing->children.push_back(node2);

		Node* node3 = new Node();
		node3->data = "������";
		planing->children.push_back(node3);
	}

	// ���α׷��� ��
	Node* art = new Node();
	art->data = "��Ʈ";
	root->children.push_back(art);
	{
		Node* node1 = new Node();
		node1->data = "��ȭ";
		art->children.push_back(node1);

		Node* node2 = new Node();
		node2->data = "���";
		art->children.push_back(node2);

		Node* node3 = new Node();
		node3->data = "��";
		art->children.push_back(node3);
	}

	return root;
}

void PrintTree(Node* node, int depth = 0)
{
	// Tree�� ������ȸ : �θ� - ���� �ڽĵ� - ������ �ڽĵ�
	// Tree�� ������ȸ : �����ڽĵ� - �θ� - ������ �ڽĵ�
	// Tree�� ������ȸ : �����ڽĵ� - �������ڽĵ� - �θ�

	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}

	// ������ȸ
	 cout << node->data << endl;

	for (auto child : node->children)
	{
		PrintTree(child, depth + 1);
	}
	// ������ȸ
	// cout << node->data << endl;
}

int main()
{
	Node* root = CreateTree();

	PrintTree(root);

	return 0;
}