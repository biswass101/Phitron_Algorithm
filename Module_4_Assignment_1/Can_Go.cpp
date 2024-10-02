#include<bits/stdc++.h>
using namespace std;
char graph[1005][1005];
bool vis[1005][1005];
int n, m; 
vector<pair<int,int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValidCell(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int si, int sj)
{
    // cout << "he" << endl;
    vis[si][sj] = true;
    for(int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(isValidCell(ci, cj) && graph[ci][cj] != '#' && !vis[ci][cj])
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
    pair<int, int> get_b_cell;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(graph[i][j] == 'A') dfs(i, j);
            if(graph[i][j] == 'B') get_b_cell.first = i, get_b_cell.second = j;
        }
    }
    // cout << get_b_cell.first << " "  << get_b_cell.second << endl;
    if(vis[get_b_cell.first][get_b_cell.second]) cout << "YES" << endl;
    else cout << "NO";
    return 0;
}