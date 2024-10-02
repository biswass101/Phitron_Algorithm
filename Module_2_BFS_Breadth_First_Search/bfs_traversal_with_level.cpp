#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> graph[N];
vector<bool> visited(N, false);
vector<int> level(N, -1);
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        // cout << parent << endl;
        for(auto child : graph[parent])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
}
int main()
{
    int n, e; cin >> n >> e;
    
    while(e--)
    {
        int u, v; cin >>u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src; cin >> src;
    bfs(src);
    for(int i = 0; i < n; i++)
    {
        cout << i << " : " << level[i] << endl;
    }
    return 0;
}