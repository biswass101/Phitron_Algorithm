#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 7;
const ll INF = 1e18 + 7;
ll graph[N][N];
int main()
{
    ll n, e;
    cin >> n >> e;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
            if (i == j)
                graph[i][j] = 0;
        }
    }
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if(graph[u][v] > w) graph[u][v] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    int q; cin >> q;
    while(q--)
    {
        int src, dest; cin >> src >> dest;
        if(graph[src][dest] != INF) cout << graph[src][dest] << endl;
        else cout << -1 << endl;
    }
    return 0;
}