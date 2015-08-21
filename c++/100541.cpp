/*
Author: aseemraj
Problem: 100541b
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
const int MOD = 1e6;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    ll n, safe, nextStep, sq;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ans = 0;
        safe = n+1;
        sq = sqrt(n);
        int i;
        for(i = 1; i <= sq; i++)
        {
            nextStep = n/i + 1;
            ans += (safe - nextStep)*(i-1) + n/i;
            ans %= MOD;
            safe = nextStep;
        }
        while(i<nextStep)
        {
            ans += n/i;
            ans %= MOD;
            i++;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
