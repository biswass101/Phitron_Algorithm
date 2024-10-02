#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
vector<int> graph[N];
vector<bool> visited(N, false);
void bfs(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;
    while(!q.empty())
    {
        pair<int, int> pr = q.front();
        int parent = pr.first;
        int level = pr.second;
        q.pop();

        cout << "Node: " << parent << " Level: " << level << endl;

        for(auto child : graph[parent])
        {
            if(!visited[child])
            {
                q.push({child, level + 1});
                visited[child] = true;
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
    int src; cin >> src;
    bfs(src);
    return 0;
}