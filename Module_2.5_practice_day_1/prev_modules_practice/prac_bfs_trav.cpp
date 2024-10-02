#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
vector<int> graph[N];
vector<bool> visited(N, false);
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for(auto child : graph[parent])
        {
            if(!visited[child])
            {
                q.push(child);
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