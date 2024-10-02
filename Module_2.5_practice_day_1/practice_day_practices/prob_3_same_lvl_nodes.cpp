#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
vector<int> graph[N];
vector<bool> visited(N, false);
vector<int> lvlNodes(int src, int t_lvl)
{
    vector<int> res;
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;
    while(!q.empty())
    {
        pair<int, int> pr = q.front();
        int parent = pr.first;
        int level = pr.second;
        q.pop();

        if(level == t_lvl) res.push_back(parent);

        for(auto child : graph[parent])
        {
            if(!visited[child])
            {
                q.push({child, level + 1});
                visited[child] = true;
            }
        }
    }

    return res; 
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
    int t_lvl; cin >> t_lvl;
    vector<int>res = lvlNodes(0, t_lvl);
    sort(res.begin(), res.end(), greater<int>());
    for(auto x : res) cout << x << " ";
    cout << endl;
    return 0;
}