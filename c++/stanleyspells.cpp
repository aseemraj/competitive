/*
Author: aseemraj
Problem: stanleyspells
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
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
const ll INF = 1000000000000;

VI adj[10005];
ll dp[10005][305];
int par[10005];
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m, k, x, y, root;
    ll mx;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        ll c[n];
        loop(i, 0, n)
        {
            adj[i].clear();
            par[i] = -1;
            cin>>c[i];
        }
        loop(i, 0, n-1)
        {
            cin>>x>>y;
            adj[x].PB(y);
            par[y] = x;
        }
        loop(i, 0, n)
        {
            if(par[i] == -1)
            {
                root = i;
                break;
            }
        }
        loop(i, 0, k+1)
            dp[root][i] = -INF;
        dp[root][0] = c[root];
        if(k>0)
            dp[root][1] = c[root]*m;

        queue<int> q;
        for (vector<int>::iterator it = adj[root].begin(); it != adj[root].end(); it++)
        {
            q.push(*it);
        }

        int v;
        while(!q.empty())
        {
            v = q.front();
            q.pop();
            dp[v][0] = max(dp[par[v]][0] + c[v], c[v]);
            if(k > 0)
            {
                dp[v][1] = max(dp[par[v]][1] + c[v], dp[par[v]][0] + c[v]*m);
                dp[v][1] = max(dp[v][1], c[v]*m);
            }
            loop(i, 2, k+1)
            {
                dp[v][i] = max(dp[par[v]][i] + c[v], dp[par[v]][i-1] + c[v]*m);
            }
            for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
            {
                q.push(*it);
            }
        }

        mx = -INF;
        loop(i, 0, n)
        {
            loop(j, 0, k+1)
            {
                mx = max(dp[i][j], mx);
            }
        }
        cout<<mx<<"\n";
    }
    return 0;
}
