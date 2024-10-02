#include<bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> graph[N];
int dis[N];
class cmp
{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second;
        }
};
void dijkstra(int src)
{
    // queue<pair<int, int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>q;
    q.push({src, 0});

    dis[src] = 0;

    while(!q.empty())
    {
        pair<int, int> parent = q.top();
        q.pop();

        int node = parent.first;
        int cost = parent.second;

        for(auto child : graph[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
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
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    for(int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for(int i = 0; i < n; i++)
    {
        cout << i  << " --> " << dis[i] << endl;
    }
    return 0;
}