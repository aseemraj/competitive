/*
Author: aseemraj
Problem: DIVLAND
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

V(P(int, PI)) edge;
PI deg[1000005];
bool fr[1000005];
bool city[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, a, b, c;
    cin>>n>>m;
    loop(i, 0, n)deg[i].S = i;
    loop(i, 0, m)
    {
        cin>>a>>b>>c;
        deg[b].F++;
        edge.PB(P(int, PI)(c, PI(a, b)));
    }
    sort(ALL(edge));
    reverse(ALL(edge));
    int cnt = 0;
    for(V(P(int, PI))::iterator it=edge.begin(); it!=edge.end(); it++)
    {
        int u = it->S.F, v = it->S.S;
        if(!city[u])
            city[u] = 1, cnt++;
        if(cnt == n/2)
            break;
        if(!city[v])
            city[v] = 1, cnt++;
        if(cnt == n/2)
            break;
    }
    ll val1=0;
    for(V(P(int, PI))::iterator it=edge.begin();it!=edge.end();it++)
    {
        int u=it->S.F;
        int v=it->S.S;
        int w=it->F;
        if(city[u] != city[v])
            val1+=w;
    }

    sort(deg, deg+n);
    for(int i=0; i<n/2; i++)
        fr[deg[i].S]=1;
     
    ll val2=0;
    for(V(P(int, PI))::iterator it=edge.begin();it!=edge.end();it++)
    {
        int u=it->S.F;
        int v=it->S.S;
        int w=it->F;
        if(fr[u]!=fr[v])
            val2+=w;
    }
    if(val1<=val2)
    {
        loop(i, 0, n)
            if(city[i])
                cout<<i<<' ';
    }
    else
    {
        loop(i, 0, n/2)
            cout<<deg[i].S<<' ';
    }

    return 0;
}
