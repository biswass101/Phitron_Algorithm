#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
vector<int> graph[N];
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        vector<int> res;
        for(auto child : graph[a]) res.push_back(child);
        sort(res.begin(), res.end(), greater<int>());
        if(res.size())
        {
            for(auto x : res) cout << x << " ";
            cout << endl;
        }
        else cout << "-1" << endl;
    }
    return 0;
}