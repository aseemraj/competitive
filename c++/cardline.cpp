/*
Author: aseemraj
Problem: cardline
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

int downof[2005];
int a[2005];
int b[2005];
bool visited[2005];

int dfs(int u)
{
    if(visited[u])return 0;
    visited[u] = 1;
    return 1 + dfs(downof[u]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    int t, n, ans, singles, newcnt;
    cin>>t;
    while(t--)
    {
        ans = 0;
        singles = 0;
        cin>>n;
        loop(i, 0, n)cin>>a[i];
        loop(i, 0, n)
        {
            cin>>b[i];
            downof[a[i]] = b[i];
        }
        memset(visited, 0, sizeof visited);
        loop(i, 1, n+1)
        {
            if(!visited[i])
            {
                newcnt = dfs(i);
                if(newcnt == 1)
                    singles++;
                else
                    ans = max(ans, newcnt);
            }
        }
        if(ans - 1 > singles)
            cout<<ans-1<<"\n";
        else
            cout<<singles<<"\n";
    }
    return 0;
}
