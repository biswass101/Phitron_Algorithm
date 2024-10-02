#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> graph;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph.push_back({u, v});
    }

    for (auto pr : graph)
        cout << pr.first << " " << pr.second << endl;
    return 0;
}