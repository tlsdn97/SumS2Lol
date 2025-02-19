#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> S;

void Input()
{
	cin >> N >> M;
	arr.resize(N + 1,0);
	S.resize(N + 1,0);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

}

void MakeSum()
{
	for (int i = 1; i <= N; i++)
	{
		S[i] = S[i-1] + arr[1];
	}
}

void Solution()
{
	for (int i = 0; i < M; i++)
	{

		int start, end;

		cin >> start >> end;
		
		cout << S[end] - S[start - 1] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);


	Input();
	MakeSum();
	Solution();

	return 0;

}