#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 7;
ll n, e;
ll graph[N][N];
int main()
{
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INT_MAX;
            if (i == j)
                graph[i][j] = 0;
        }
    }
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    //floyd warshall--->
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
    int src; cin >> src;
    int t; cin >> t;
    while(t--)
    {
        int desti, cost; cin >> desti >> cost;
        graph[src][desti] <= cost ? cout << "YES" << endl : cout << "NO" << endl;
    }
}