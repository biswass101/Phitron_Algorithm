#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u, v, w;
        Edge(int u, int v, int w)
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
const int N = 1e5 + 7;
int parent[N];
int parentSize[N];
void sett(int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int findL(int node) // we can find leader by using this fucntion
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void unionn(int a, int b)
{
    int leaderA = findL(a);
    int leaderB = findL(b);

    if(leaderA != leaderB)
    {   
        //Union by size
        if(parentSize[leaderA] > parentSize[leaderB])
        {
            //A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            //A or B can be leader
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, e; cin >> n >> e;
    sett(n);
    vector<Edge> edgeList;
    while(e--)
    {
        int u, v, w; cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    int tt = 0;
    for(auto ed : edgeList)
    {
       int leaderU = findL(ed.u);
       int leaderV = findL(ed.v);

       if(leaderU == leaderV) continue; //same group
       else
       {
            unionn(ed.u, ed.v);
            tt += ed.w;
       }
    }
    cout << tt << endl;
    return 0;
}