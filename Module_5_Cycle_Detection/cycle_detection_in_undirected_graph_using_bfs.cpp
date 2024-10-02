#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
vector<bool> vis(N, false);
vector<int> par(N, -1);
bool ans;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        // cout << parent << " ";
        for(auto child : graph[parent])
        {
            if(vis[child] && par[parent] != child)
            {
                ans = true;
            }
            if(!vis[child])
            {
                vis[child] = true;
                par[child] = parent;
                q.push(child);
            }
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
            bfs(i);
        }
    }
    ans ? cout << "Cycle Detected" : cout << "Not Cycle" << endl;
    return 0;
}