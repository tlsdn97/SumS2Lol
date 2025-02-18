#pragma once

#include <iostream>

using namespace std;

struct Node
{
	Node() {}
	Node(int key) { this->key = key; }

	int data = 0;
	int key = -1;

	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	Node* parent = nullptr;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(int key);
	void PrintTree(Node* root);

	Node* Search(Node* root, int key); // key���� ������ ��� ��ȯ
	Node* Min(Node* root); // node���� �����ϴ� Ʈ������ ������������ ������ ��� ��ȯ
	Node* Max(Node* root); //   "                      ����ū��    "

	void Delete(Node* node);

	Node* root = nullptr;
private:
	Node* Previous(Node* root); // �Ű����� root���� ��ĭ �� ���� ��
	Node* Next(Node* root); // �Ű����� root���� ��ĭ �� ū ��

	void Replace(Node* node1, Node* node2);
};