#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
char graph[N][N];
bool vis[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m; 
bool valid(int i , int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    
    for(int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && graph[ci][cj] != '-' && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    int si, sj, di, dj; cin >> si >> sj >> di >> dj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);
    vis[di][dj] ? cout << "YES" : cout << "NO" << endl; 
    return 0;
}