#include <bits/stdc++.h>
using namespace std;
bool vis[20][20];
int dis[20][20];
char graph[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        // cout << par.first << " " << par.second << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second+ d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);

    //shortest distance-->
    cout << dis[2][3];
    return 0;
}