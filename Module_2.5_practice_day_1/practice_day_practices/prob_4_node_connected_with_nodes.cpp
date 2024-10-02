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
    int node; cin >> node;
    
    cout << graph[node].size() << endl;
    return 0;
}