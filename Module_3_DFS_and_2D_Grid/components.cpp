#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
bool vis[N];
void dfs(int parent)
{
    // cout << parent << endl;
    vis[parent] = true;
    for(auto child : graph[parent])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e; cin >> n >> e;
    while(e--)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    int comp = 0;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            comp++;
        }
    }
    cout << comp << endl;
    return 0;
}