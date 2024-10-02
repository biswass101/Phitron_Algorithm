#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
vector<bool> vis(1005, false);
vector<int> lvl(1005, -1);
vector<int> par(1005, -1);
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    lvl[src] = 0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(auto child : graph[parent])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                lvl[child] = lvl[parent] +1;
                par[child] = parent;
            }
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
    int src, dest; cin >> src >> dest;
    bfs(src);
    int x = dest;
    vector<int> path;
    while(x != -1)
    {
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    for(auto x : path) cout << x << " ";
    cout << endl;
    return 0;
}