/*
Author: aseemraj
Problem: chplgns
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
PI mnx[100005];
int ans[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, x, y, m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        loop(i, 0, n)mnx[i].F=50, mnx[i].S=i;
        loop(i, 0, n)
        {
            cin>>m;
            while(m--)
            {
                cin>>x>>y;
                mnx[i].F = min(mnx[i].F, x);
            }
        }
        sort(mnx, mnx + n);
        loop(i, 0, n)
            ans[mnx[i].S] = n-i-1;
        loop(i, 0, n)
            cout<<ans[i]<<' ';
        cout<<"\n";
    }
    return 0;
}
