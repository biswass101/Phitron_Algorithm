#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int graph[n][n];
    memset(graph, 0, sizeof(graph));
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        //if the graph is directed then next line won't be written
        graph[v][u] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    if(graph[3][4]) cout << "connection ache" << endl;
    else cout << "connection nai" << endl;
    return 0;
}