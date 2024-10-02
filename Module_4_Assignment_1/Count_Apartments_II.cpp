#include<bits/stdc++.h>
using namespace std;
char graph[1005][1005];
bool vis[1005][1005];
int n, m; 
int cnt_ap_cell = 0;
vector<pair<int,int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValidCell(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int si, int sj)
{
    cnt_ap_cell++;
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
    vector<int> apNum;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(graph[i][j] != '#' && !vis[i][j])
            {
                dfs(i, j);
                apNum.push_back(cnt_ap_cell);
                cnt_ap_cell = 0;
            }
        }
    }
    if(apNum.size())
    {
        sort(apNum.begin(), apNum.end());
        for(auto x : apNum) cout << x << ' ';
    }
    else cout << '0' << endl;
    return 0;
}