#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int graph[N][N];
int main()
{
    int n, e; cin >> n >> e;
    memset(graph, 0, sizeof(graph));
    while(e--)
    {
        int u, v; cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cout << graph[i][j] << " ";
        cout << endl;
    }
    if(graph[5][6]) cout << "Ache re bhai" << endl;
    return 0;
}