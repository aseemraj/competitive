/*
Author: aseemraj
Problem: 100712f
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

V(P(ll, PI)) edges;

struct subset
{
    int parent;
    int rank;
} subsets[100005];

int find(int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
 
    return subsets[i].parent;
}

void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m, u, v, c, pu, pv;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        loop(i, 1, n+1)
            subsets[i].parent = i, subsets[i].rank = 0;

        loop(i, 0, m)
        {
            cin>>u>>v>>c;
            edges.PB(make_pair(c, make_pair(u, v)));
        }

        sort(ALL(edges));

        int mx = 0, i = 0;
        while(i<n-1)
        {
            c = edges[i].F;
            u = edges[i].S.F;
            v = edges[i].S.S;
            // cout<<"Edge "<<i+1<<": "<<c<<' '<<u<<' '<<v<<"\n";
            // cout<<"Components: "<<u<<": "<<comp[u]<<' '<<v<<": "<<comp[v]<<"\n";
            pu = find(u);
            pv = find(v);
            if(pu != pv)
            {
                mx = c;
                Union(pu, pv);
                i++;
            }
        }

        cout<<mx<<"\n";
    }
    
    return 0;
}
