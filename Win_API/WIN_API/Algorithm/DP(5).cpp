#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N;
int cache[301];


int Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    for (int i = 0; i < 301; i++)
    {
        cache[i] = -1;
    }
}

int DP(int n)
{
    if (n < 0)
        return 0;

    int& ref = cache[n];
    if (ref != -1)
        return ref;

    if(n > 0)
        ref = v[n] + v[n - 1] + DP(n - 3);

    ref = max(ref, v[n] + DP(n - 2));

    return ref;
    
}


int main()
{ 
    Input();

    cout << DP(v.size() -1) << endl;

    return 0;
}