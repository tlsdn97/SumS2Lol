#include "BST.h"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
	// TODO : ��� ��� ����
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node(key);

	if (root == nullptr)
	{
		root = newNode;
		return;
	}

	Node* node = root;
	Node* parent = nullptr;

	// ���ȣ�� <-> �ݺ���
	// �ڸ�ã��, �θ�ã��
	while (true)
	{
		if (node == nullptr)
			break;

		parent = node;
		if (key < node->key)
		{
			node = node->leftChild;
		}
		else
		{
			node = node->rightChild;
		}
	}

	newNode->parent = parent;
	if (key < parent->key)
	{
		parent->leftChild = newNode;
	}
	else
	{
		parent->rightChild = newNode;
	}
}

void BinarySearchTree::PrintTree(Node* node)
{
	if (node == nullptr)
		return;

	// ������ȸ : �θ� - �����ڽĵ� - �������ڽĵ�
	// ������ȸ : ���� - �θ� - ������
	// ������ȸ : ���� - ������ - �θ�

	PrintTree(node->leftChild);
	PrintTree(node->rightChild);
	cout << node->key << endl;
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr)
		return nullptr;

	if (node->key == key)
		return node;

	if (key > node->key)
		return Search(node->rightChild, key);
	else
		return Search(node->leftChild, key);
}

Node* BinarySearchTree::Min(Node* node)
{
	if (node->leftChild == nullptr)
		return node;

	return Min(node->leftChild);
}

Node* BinarySearchTree::Max(Node* node)
{
	if (node->rightChild == nullptr)
		return node;

	return Max(node->rightChild);
}

Node* BinarySearchTree::Previous(Node* node)
{
	if (node->leftChild == nullptr)
		return nullptr;

	return Max(node->leftChild);
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->rightChild == nullptr)
		return nullptr;

	return Min(node->rightChild);
}

void BinarySearchTree::Replace(Node* node1, Node* node2)
{
	if (node1->parent == nullptr)
		root = node2;

	else if (node1 == node1->parent->leftChild)
	{
		node1->parent->leftChild = node2;
	}
	else
	{
		node1->parent->rightChild = node2;
	}

	if (node2 != nullptr)
		node2->parent = node1->parent;

	delete node1;
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->leftChild == nullptr)
	{
		Replace(node, node->rightChild);
	}
	else if (node->rightChild == nullptr)
	{
		Replace(node, node->leftChild);
	}
	else
	{
		// ����, ������ �ڽ��� �� �ִ� ���
		Node* prev = Previous(node);
		node->data = prev->data;
		node->key = prev->key;

		Delete(prev);
	}
}
