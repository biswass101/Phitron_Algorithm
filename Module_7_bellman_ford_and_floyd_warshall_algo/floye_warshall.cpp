#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    // printing part-->
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}