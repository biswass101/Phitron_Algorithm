#include <bits/stdc++.h>
#define ll long long int
#define INF 1e18 + 7
using namespace std;
class Edge
{
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
const int N = 1e3 + 7;
long long int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        EdgeList.push_back(Edge(u, v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    int src; cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            ll u, v, w;
            u = ed.u, v = ed.v, w = ed.w;
            // relaxation-->
            if (dis[u] < INF && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    // Neg. Cycle detection part-->
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        ll u, v, w;
        u = ed.u, v = ed.v, w = ed.w;
        // relaxation-->
        if (dis[u] < INF && dis[u] + w < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if(cycle) cout << "Negative Cycle Detected" << endl;
    else
    {
        int t; cin >> t;
        while(t--)
        {
            int d; cin >> d;
            if(dis[d] != INF) cout << dis[d] << endl;
            else cout << "Not Possible" << endl;
        }
    }
    return 0;
}