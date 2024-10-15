#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
using namespace std;
const ll N = 1e5 + 7;
const ll INF = 1e18 + 7;
vector<pi> graph[N];
ll dis[N];
ll par[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();

        ll parentNode = parent.first;
        ll parentCoast = parent.second;

        for (pi child : graph[parentNode])
        {
            ll childNode = child.first;
            ll childCoast = child.second;

            // path relaxation-->
            if (parentCoast + childCoast < dis[childNode])
            {
                dis[childNode] = parentCoast + childCoast;
                pq.push({childNode, dis[childNode]});
                par[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    for (int i = 1; i <= n; i++)
        par[i] = -1;
    dijkstra(1);
    if (dis[n] != INF)
    {
        ll x = n;
        vector<ll> paths;
        while (x != -1)
        {
            paths.push_back(x);
            x = par[x];
        }
        reverse(paths.begin(), paths.end());
        for (auto x : paths)
            cout << x << ' ';
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}