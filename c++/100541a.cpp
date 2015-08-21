/*
Author: aseemraj
Problem: 100541a
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

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    ll w;
    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        ll p[n];
        ll mx[n];
        loop(i, 0, n)
            cin>>p[i];
        mx[n-1] = p[n-1];
        rloop(i, 0, n-1)
            mx[i] = max(mx[i+1], p[i]);
        ll ans = 0;
        loop(i, 0, n-1)
        {
            ans = max(ans, (w/p[i])*(mx[i+1] - p[i]));
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
