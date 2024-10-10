#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Edge
{
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
const ll N = 1e5 + 7;
vector<ll> graph[N];
ll parent[N];
ll parentSize[N];
bool vis[N];
int cnt = 0;
void dfs(ll par)
{
    vis[par] = true;
    cnt++;
    for (auto child : graph[par])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
void sett(ll n)
{
    for (ll i = 0; i < n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
ll findL(ll node) // we can find leader by using this fucntion
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void unionn(ll a, ll b)
{
    ll leaderA = findL(a);
    ll leaderB = findL(b);

    if (leaderA != leaderB)
    {
        // Union by size
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            // A or B can be leader
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    ll n, e; 
    cin >> n >> e;
    ll edge = e;
    sett(n);
    int cnt2 = 0;
    vector<Edge> edgeList;
    while (e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edgeList.push_back(Edge(u, v, w));
    }
    dfs(1);
    if (cnt == n)
    {
        sort(edgeList.begin(), edgeList.end(), cmp);
        ll tt = 0;
        for (auto ed : edgeList)
        {
            ll leaderU = findL(ed.u);
            ll leaderV = findL(ed.v);

            if (leaderU == leaderV)
                continue;
            else
            {
                unionn(ed.u, ed.v);
                tt += ed.w;
                cnt2++;
            }
        }
        cout<< (edge - cnt2) << ' ' << tt << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }
    return 0;
}