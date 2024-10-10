#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
vector<bool> vis(N, false);
vector<int> par(N, -1);
bool ans;
int cnt = 0;
void dfs(int parent)
{
    vis[parent] = true;
    // cout << parent << " ";
    for(auto child : graph[parent])
    {
        if(vis[child] && par[parent] != child)
        {
            ans = true;
            cnt++;
        }
        if(!vis[child])
        {
            par[child] = parent;
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    ans = false;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    // for(int i = 0; i < n; i++) cout << i << " : " << par[i] << endl;
    cout << cnt/2 << endl;
    return 0;
}