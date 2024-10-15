#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
bool vis[N];
int dis[N];
int par[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    vis[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        // cout << parent << " ";
        for (auto child : graph[parent])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[parent] + 1;
                par[child] = parent;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(par, -1, sizeof(par));
    bfs(1);
    if (dis[n] != -1)
    {
        int x = n;
        vector<int> paths;
        while (x != -1)
        {
            paths.push_back(x);
            x = par[x];
        }
        reverse(paths.begin(), paths.end());
        cout << paths.size() << endl;
        for (auto x : paths)
            cout << x << " ";
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}