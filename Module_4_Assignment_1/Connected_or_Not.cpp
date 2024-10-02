#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int graph[N][N];
bool vis[N][N];
int main()
{
    int n, e;
    cin >> n >> e;
    memset(graph, 0, sizeof(graph));
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            cout << "YES" << endl;
        else
        {
            if (graph[a][b])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}