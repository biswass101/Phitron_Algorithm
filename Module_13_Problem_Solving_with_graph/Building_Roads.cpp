#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
bool vis[N] = {false};
void dfs(int par)
{
    vis[par] = true;
    for(int child : graph[par])
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

    vector<int> lead;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            lead.push_back(i);
            dfs(i);
        }
    }

    cout << lead.size() - 1 << endl;
    int before = lead[0];
    for(int i = 1; i < lead.size(); i++)
    {
        cout << before << " " << lead[i] << endl;
        before = lead[i];
    }
    return 0;
}