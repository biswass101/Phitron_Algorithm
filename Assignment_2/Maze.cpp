#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 1e3 + 5;
vector<string> graph;
int visited[N][N];
int level[N][N];
pii prnt[N][N];
int n, m;
vector<pii> dir =
    {make_pair(0, -1), make_pair(0, 1),
     make_pair(-1, 0), make_pair(1, 0)};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pii> qu;
    qu.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!qu.empty())
    {
        pii parent = qu.front();
        int i = parent.first;
        int j = parent.second;
        qu.pop();

        for (auto d : dir)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && graph[ni][nj] != '#')
            {
                qu.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                prnt[ni][nj] = {i, j};
            }
        }
    }
}
int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'R')
                si = i, sj = j;
            if (x[j] == 'D')
                di = i, dj = j;
        }
        graph.push_back(x);
    }

    bfs(si, sj);
    if (visited[di][dj])
    {
        vector<pii> path;
        pii cur = {di, dj};
        while (!(cur.first == si && cur.second == sj))
        {
            path.push_back(cur);
            cur = prnt[cur.first][cur.second];
        }
        path.push_back({si, sj});
        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size() - 1; i++)
        {
            graph[path[i].first][path[i].second] = 'X';
        }
        for (auto str : graph)
            cout << str << endl;
    }
    else
    {
        for (auto str : graph)
            cout << str << endl;
    }

    return 0;
}