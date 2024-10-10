#include<bits/stdc++.h>
using namespace std;
char graph[1005][1005];
bool vis[1005][1005];
int n, m; 
int minCnt = INT_MAX;
int cnt = 0;
vector<pair<int,int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValidCell(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int si, int sj)
{
    cnt++;
    vis[si][sj] = true;
    for(int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(isValidCell(ci, cj) && graph[ci][cj] != '-' && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && graph[i][j] == '.')
            {
                dfs(i, j);
                minCnt = min(minCnt, cnt);
                cnt = 0;
            }
        }
    }

    if(minCnt != INT_MAX) cout << minCnt << endl;
    else cout << -1 << endl;
    return 0;
}