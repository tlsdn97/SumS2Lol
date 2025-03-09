#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

#include "BST.h"

// BST
// ����Ž��Ʈ��
// - ���� : logN
// - (key)Ž�� : logN
// - ���� : logN
// 
// �ڰ����� ����Ž��Ʈ��
// - �����Ʈ�� (map)
// - (B-Ʈ�� => DB)
// - AVL

//           ����Ž��Ʈ��    vs     �ؽ����̺� (ǥ)
//            Node(key,data)       pair(key, data) 
//           key�� ����             �ؽ�(key...Algorithm) => Index
// Ž���ð�    logN                  1
// ���Խð�    logN                  1
// ����        logN                  1

// => ����Ž��Ʈ���� ���� ����
// 1. �����͸� ���� ����. (������ ����ȭ�� �Ǿ������� �ؽ����̺��� ���� ���� �� �ִ�.)
// 2. �ؽ��Լ��� ������ ������ ��� 'ü�̴�' �߻�

class Player
{
public:
	bool operator<(const Player& other) const
	{
		return hp < other.hp;
	}

	bool operator==(const Player& other) const
	{
		return hp == other.hp;
	}

	int hp;
	int atk;
};

int main()
{
	BinarySearchTree tree;
	tree.Insert(100);
	tree.Insert(50);
	tree.Insert(25);
	tree.Insert(75);
	tree.Insert(150);
	tree.Insert(110);
	tree.Insert(200);
	tree.Insert(99);

	tree.PrintTree(tree.root);

	map<string, int> m;

	if(m.count("Hanil1") == 0)
		m["Hanil1"] = 1;	
	auto iter = m.insert(make_pair<string, int>("Hanil2", 2));

	for (auto p : m)
	{
		cout << p.first << "... " << p.second << endl;
	}

	map<Player, int> pm;
	pm[{10, 5}] = 5;

	return 0;
}
