#include "framework.h"
#include "Player.h"

#include "Maze.h"
#include "Block.h"

Player::Player(shared_ptr<Maze> maze)
: _maze(maze)
{
	_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);

	AStart(_maze.lock()->StartPos(), _maze.lock()->EndPos());
}

Player::~Player()
{
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		_pathIndex = 0;
		_maze.lock()->CreateMaze_Kruskal();

		_path.clear();

		int randNum = 0;
		switch (randNum)
		{
		case 0:
			AStart(_maze.lock()->StartPos(), _maze.lock()->EndPos());
			break;
		case 1:
			BFS(_maze.lock()->StartPos());
			break;
		case 2:
			Djikstra(_maze.lock()->StartPos());
			break;
		case 3:
			RightHand();
			break;

		default:
			break;
		}



		return;
	}

	_delayTime += 0.3f;
	if (_delayTime > 1.0f)
	{
		_delayTime = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex > 0)
		{
			_maze.lock()->SetBlockType(_path[_pathIndex - 1], Block::Type::FOOTPRINT);
		}
		_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);

		_pathIndex++;
	}
}

void Player::RightHand()
{
	shared_ptr<Maze> maze = _maze.lock();

	Vector pos = maze->StartPos();
	Vector endPos = maze->EndPos();

	int curDir = Direction::UP;
	while (true)
	{
		if (pos == endPos)
			break;

		int newDir = (curDir - 1 + DIR_COUNT) % DIR_COUNT; // ��ȯ
		Vector oldVector = pos + frontPos[curDir]; // ���� �ٶ󺸰� �ִ� �������� ��ĭ +
		Vector newVector = pos + frontPos[newDir]; // ������ �������� ��ĭ +

		// ���������� �� �� �ִ�? => ���������� ������ �ٲٰ� �� �������� GO
		if (Cango(newVector))
		{
			curDir = newDir;
			pos = newVector;
			_path.push_back(pos);
		}

		// �������� �����ְ� �� ������ �շ��ִ�? => �״�� ����
		else if (Cango(oldVector))
		{
			pos = oldVector;
			_path.push_back(pos);
		}

		// ������ �����ְ�, ������⵵ �����ִ� => �������� ȸ��
		else
		{
			curDir = (curDir + 1 + DIR_COUNT) % DIR_COUNT;
		}
	}

	stack<Vector> s;
	// ����Ŭ ó��
	for (int i = 0; i < _path.size() - 1; i++)
	{
		maze->SetBlockType(_path[i], Block::Type::SEARCHED);

		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
			s.push(_path[i]);
	}

	_path.clear();
	while (true)
	{
		if (s.empty() == true)
			break;
		Vector top = s.top();
		_path.push_back(top);
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::BFS(Vector start)
{
	_discovered = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));
	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));

	queue<Vector> q;
	q.push(start);
	_discovered[start.y][start.x] = true;
	_parent[start.y][start.x] = start;

	while (true)
	{
		Vector here = q.front();
		q.pop();

		// ���� �����̸� �ݺ� �׸�.
		if (here == _maze.lock()->EndPos())
			break;

		for (int i = 0; i < 8; i++)
		{
			Vector there = here + frontPos[i];

			// here�� there�� ����?
			if (there == here) continue;
			// there�� �� �� �ִ� ���̳�?
			if (Cango(there) == false) continue;
			// there�� �湮�� �Ǿ��ֳ�?
			if (_discovered[there.y][there.x] == true) continue;

			q.push(there);
			_discovered[there.y][there.x] = true;
			_parent[there.y][there.x] = here;
			_maze.lock()->SetBlockType(there, Block::Type::SEARCHED);
		}
	}

	// ������ �������׼� �߰ߵǾ����� Ÿ�� �ö󰡺���
	Vector vertex = _maze.lock()->EndPos();
	_path.push_back(vertex);
	while (true)
	{
		// parent�� start�����̸� �׸�
		if (vertex == start)
			break;
		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::Djikstra(Vector start)
{
	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
	_best = vector<vector<int>>(MAX_Y, vector<int>(MAX_X, INT_MAX));
	priority_queue<Vertex_Djikstra, vector<Vertex_Djikstra>, greater<Vertex_Djikstra>> pq;

	_parent[start.y][start.x] = start;
	_best[start.y][start.x] = 0;
	pq.push(Vertex_Djikstra(start, 0));

	while (true)
	{
		if (pq.empty())
			break;

		Vertex_Djikstra hereV = pq.top();
		pq.pop();
		Vector herePos = hereV.pos;

		// ����
		if (herePos == _maze.lock()->EndPos())
			break;

		// ����ɸ� Vertex�� �����µ� �� ���� best�� �־���.
		if (_best[herePos.y][herePos.x] < hereV.cost)
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector therePos = herePos + frontPos[i];

			if (Cango(therePos) == false)
				continue;

			int thereCost = 0;
			// thereCost ã��
			if (i < 4)
				thereCost = hereV.cost + 10;
			else
				thereCost = hereV.cost + 14;

			// ���� ã�Ƴ��� best�� �� ���Ҵ� => ��������� ���� ������
			if (_best[therePos.y][therePos.x] < thereCost)
				continue;

			// ����
			Vertex_Djikstra thereV(therePos, thereCost);
			pq.push(thereV);
			_parent[therePos.y][therePos.x] = herePos;
			_best[therePos.y][therePos.x] = thereCost;
			_maze.lock()->SetBlockType(therePos, Block::Type::SEARCHED);
		}
	}

	// ������ �������׼� �߰ߵǾ����� Ÿ�� �ö󰡺���
	Vector vertex = _maze.lock()->EndPos();
	_path.push_back(vertex);
	while (true)
	{
		// parent�� start�����̸� �׸�
		if (vertex == start)
			break;
		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::AStart(Vector start, Vector end)
{
	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
	_best = vector<vector<int>>(MAX_Y, vector<int>(MAX_X, INT_MAX));
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

	_parent[start.y][start.x] = start;
	_best[start.y][start.x] = 0 + start.ManhattanDistance(end) * 10;
	pq.push(Vertex(start, 0, start.ManhattanDistance(end) * 10));

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		Vector here = hereV.pos;

		// ���� üũ
		if (here == end)
			break;

		pq.pop();

		// ������ �� ���� ��θ� �߰� �� ���� ��
		if (hereV.f > _best[here.y][here.x])
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector there = here + frontPos[i];

			if (Cango(there) == false)
				continue;

			int thereG = 0;
			// thereCost ã��
			if (i < 4)
				thereG = hereV.g + 10;
			else
				thereG = hereV.g + 14;

			float thereH = there.ManhattanDistance(end) * 10;
			float thereF = thereG + thereH;
			
			// �� ���� there�� best�� ������ continue;
			if (thereF > _best[there.y][there.x])
				continue;

			Vertex thereV = Vertex(there, thereG, thereH);
			pq.push(thereV);
			_best[there.y][there.x] = thereF;
			_parent[there.y][there.x] = here;
			_maze.lock()->SetBlockType(there, Block::Type::SEARCHED);
		}
	}

	// ������ �������׼� �߰ߵǾ����� Ÿ�� �ö󰡺���
	Vector vertex = _maze.lock()->EndPos();
	_path.push_back(vertex);
	while (true)
	{
		// parent�� start�����̸� �׸�
		if (vertex == start)
			break;
		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}

	std::reverse(_path.begin(), _path.end());
}

bool Player::Cango(Vector pos)
{
	if (_maze.lock()->GetBlockType(pos) == Block::Type::BLOCKED)
		return false;
	return true;
}
