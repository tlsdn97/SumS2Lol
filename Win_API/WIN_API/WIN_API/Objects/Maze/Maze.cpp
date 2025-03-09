#include "framework.h"
#include "Maze.h"

#include "Block.h"
#include "Math/DisJointSet.h"

Maze::Maze()
{
	// offset : ������(����)���� ����߷����� Vector
	Vector offset = Vector(500, 200);

	_blocks.resize(MAX_Y);
	for (int y = 0; y < MAX_Y; y++)
	{
		_blocks[y].reserve(MAX_X);
		for (int x = 0; x < MAX_X; x++)
		{
			shared_ptr<Block> block = make_shared<Block>();
			Vector pos;
			pos.x = x * 19;
			pos.y = y * 19;
			block->SetCenter(pos + offset);
			block->SetType(Block::Type::BLOCKED);

			_blocks[y].push_back(block);
		}
	}

	CreateMaze_Kruskal();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blockV : _blocks)
	{
		for (auto block : blockV)
		{
			block->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blockV : _blocks)
	{
		for (auto block : blockV)
		{
			block->Render(hdc);
		}
	}
}

void Maze::CreateMaze()
{
	// ���α׷��Ӹ� ���� �̷� �����

	// �� �� �ִ� ��� �����
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetType(Block::Type::BLOCKED);
			}
			else
			{
				_blocks[y][x]->SetType(Block::Type::ABLE);
			}
		}
	}

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			// ������ �ձ�
			if (x == 1 && y == 1)
			{
				_blocks[y][x]->SetType(Block::Type::ABLE);
			}

			// ���� �ձ�
			if (x == MAX_X - 2 && y == MAX_Y - 2)
			{
				_blocks[y][x]->SetType(Block::Type::ABLE);
				continue;
			}

			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			// �� �Ʒ��� �ձ�
			if (x == MAX_X - 2)
			{
				_blocks[y + 1][x]->SetType(Block::Type::ABLE);
				continue;
			}

			// �� ������ �ձ�
			if (y == MAX_Y - 2)
			{
				_blocks[y][x + 1]->SetType(Block::Type::ABLE);
				continue;
			}

			// �����ϰ� �Ʒ� Ȥ�� ���������� �� �ձ�
			int randNum = rand() % 2;
			if (randNum == 0)
				_blocks[y + 1][x]->SetType(Block::Type::ABLE);
			else
				_blocks[y][x + 1]->SetType(Block::Type::ABLE);
		}
	}
}

void Maze::CreateMaze_Kruskal()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetType(Block::Type::BLOCKED);
			}
			else
			{
				_blocks[y][x]->SetType(Block::Type::ABLE);
			}
		}
	}

	// Edges
	vector<Edge> edges;

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			// ��尡 �ƴϰ� ����
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (x < MAX_X - 2)
			{
				int randCost = rand() % 100;

				Edge edge;
				edge.u = Vector((int)x, (int)y);
				edge.v = Vector((int)(x+2), (int)y);
				edge.cost = randCost;

				edges.push_back(edge);
			}

			if (y < MAX_Y - 2)
			{
				int randCost = rand() % 100;

				Edge edge;
				edge.u = Vector((int)x,(int)y);
				edge.v = Vector((int)x, (int)y + 2 );
				edge.cost = randCost;

				edges.push_back(edge);
			}
		}
	}

	std::sort(edges.begin(), edges.end(), 
		[](const Edge& a, const Edge& b)-> bool 
		{
			if (a.cost < b.cost)
				return true;
			return false;
		});

	DisJointSet set(MAX_X * MAX_Y);

	for(auto edge : edges)
	{
		int u = MAX_X * edge.u.y + edge.u.x;
		int v = MAX_X * edge.v.y + edge.v.x;

		if (set.FindLeader(u) == set.FindLeader(v))
			continue;

		set.Merge(u, v);

		int x = ((int)edge.u.x + (int)edge.v.x) / 2;
		int y = ((int)edge.u.y + (int)edge.v.y) / 2;

		_blocks[y][x]->SetType(Block::Type::ABLE);
	}
}

Block::Type Maze::GetBlockType(Vector pos)
{
	return _blocks[pos.y][pos.x]->GetBlockType();
}

void Maze::SetBlockType(Vector pos, Block::Type type)
{
	_blocks[pos.y][pos.x]->SetType(type);
}
