/*
Author: aseemraj
Problem: 
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
const int MOD = 1000000007;
ll fastexp(int a, int b)
{
    ll x=1,y=a;
    while(b>0)
    {
        if(b&1)
            x=x*y%MOD;
        y=y*y%MOD;
        b>>=1;
    }
    return x%MOD;
}

int main()
{
    int t;
    ll val, n, wj, wa;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld",&n);
        wj = (((13*fastexp(3, n-2) - 1)%MOD) * fastexp(2, MOD-2)) % MOD;
        wa = fastexp(2, n-1);
        printf("%lld\n", (wj - wa + MOD) % MOD);
    }
    return 0;
}