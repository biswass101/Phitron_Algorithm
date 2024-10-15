#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, e;
vector<int> graph[N];
bool vis[N];
void bfs(int src, int *lvl)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    lvl[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : graph[par])
        {
            if (!vis[child])
            {
                lvl[child] = lvl[par] + 1;
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> e;
    int lvl1[n];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int r, j, k;
    cin >> r >> j >> k;
    memset(vis, false, sizeof(vis));
    memset(lvl1, -1, sizeof(lvl1));
    bfs(r, lvl1);
    if (lvl1[j] != -1)
    {
        int req = (lvl1[j] + 1) / 2;
        if (req <= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}