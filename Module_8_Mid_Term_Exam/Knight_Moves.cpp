#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int visited[N][N];
int level[N][N];
int n, m;
vector<pair<int, int>> dir =
    {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> qu;
    qu.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!qu.empty())
    {
        pair<int, int> parent = qu.front();
        int i = parent.first;
        int j = parent.second;
        qu.pop();

        for (auto d : dir)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj])
            {
                qu.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}
void sett_again()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        bfs(si, sj);
        if (visited[di][dj])
            cout << level[di][dj] << endl;
        else
            cout << -1 << endl;
        sett_again();
    }
    return 0;
}