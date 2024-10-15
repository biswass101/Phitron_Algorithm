#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
const int N = 1e5 + 7;
int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        EdgeList.push_back(Edge(u, v, w));
    }
    // printing-->
    //  for(Edge ed : EdgeList)
    //  {
    //      cout << ed.u << " " << ed.v << " " << ed.w << endl;
    //  }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, w;
            u = ed.u, v = ed.v, w = ed.w;
            //relaxation-->
            if (dis[u] < INT_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i <<  " -> " << dis[i] << endl;
    }
    return 0;
}