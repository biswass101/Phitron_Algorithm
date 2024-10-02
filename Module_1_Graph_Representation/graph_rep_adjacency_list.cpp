#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> graph[n];
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //getting connections-->
    for(int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for(auto x : graph[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}