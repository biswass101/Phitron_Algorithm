#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
vector<int> graph[N];
int main()
{
    int n, e; cin >> n >> e;
    while(e--)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for(auto x : graph[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}