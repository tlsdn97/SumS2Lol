#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// �켱����ť
// 1. ��������Ʈ��
// 2. ���̷�

// �ð����⵵
// ���� : logN
// ���� : logN
// ������ : N x logN

template <typename T, typename Container = vector<T>, typename Pred = less<int>>
class PriorityQueue
{
public:
	void push(T value)
	{
		v.push_back(value);

		int now = v.size() - 1;

		while (true)
		{
			if (now <= 0)
				break;

			int parent = (now - 1) / 2;

			if (pred(v[now],v[parent]))
				break;

			std::swap(v[parent], v[now]);
			now = parent;
		}
	}

	void pop()
	{
		v[0] = v.back();
		v.pop_back();

		int now = 0;

		while (true)
		{
			int left = now * 2 + 1;
			int right = now * 2 + 2;

			// left�� ����? => ���� ��Ʈ�ۿ� ����.
			if (left >= v.size())
			{
				break;
			}

			int next = now;
			if (pred(v[next],v[left]))
			{
				next = left;
			}

			if (right < v.size() && pred(v[next], v[right]))
			{
				next = right;
			}

			// next... left, right �߿� ���� ū ��
			if (next == now)
				break;

			std::swap(v[now], v[next]);
			now = next;
		}
	}

	bool empty() { return v.empty(); }
	T top() { return v[0]; }

private:
	Container v;
	Pred pred;
};

template<typename T>
struct Less
{
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

int main()
{
	// �ִ���
	PriorityQueue<int, vector<int>, Less<int>> pq;
	pq.push(50);
	pq.push(80);
	pq.push(70);
	pq.push(100);
	pq.push(75);

	while (true)
	{
		if (pq.empty())
			break;

		int top = pq.top();
		cout << top << endl;
		pq.pop();
	}

	return 0;
}