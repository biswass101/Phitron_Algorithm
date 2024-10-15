#include<bits/stdc++.h>
using namespace std;
void convert(int n, vector<int> graph[])
{
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    for(int i = 0; i < n; i++)
    {
        for(auto child : graph[i])
        {
            mat[i][child] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, e; cin >> n >> e;
    vector<int> graph[n];
    while(e--)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    convert(n, graph);
    return 0;
}