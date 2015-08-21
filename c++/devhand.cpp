/*
Author: aseemraj
Problem: devhand
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

const int MOD = 1000000007;
ll powmod(ll a, ll b){ll x=1,y=a;while(b>0){if(b&1)x=(x*y)%MOD;y=(y*y)%MOD;b=b>>1;}return x%MOD;}
int main()
{
    ios_base::sync_with_stdio(0);
    ll t, n, k;
    ll kn, knp1, knp2, k2np1, k2np2, k3np2, invkm1, invkm13, coeff, ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ans = 0;

        kn = powmod(k, n);
        knp1 = kn*k % MOD;
        knp2 = knp1*k % MOD;
        k2np1 = (kn*kn % MOD)*k % MOD;
        k2np2 = k2np1*k % MOD;
        k3np2 = k2np2*kn % MOD;
        invkm1 = powmod(k-1, MOD-2);
        invkm13 = (invkm1*invkm1 % MOD)*invkm1 % MOD;
        
        coeff = 2*((3*n*n + 3*n + 2)%MOD) % MOD;
        ans = ans - (coeff*knp1 % MOD);

        coeff = (3*n*n - 1) % MOD;
        ans = ans+(coeff*knp2 % MOD) % MOD;

        coeff = 6*(n+1);
        ans = ans+(coeff*k2np1 % MOD) % MOD;

        ans = ans-(6*n*k2np2 % MOD) % MOD;
        ans = ans+k3np2 % MOD;

        coeff = (3*n*n + 6*n + 2) % MOD;
        ans = ans+(coeff*kn % MOD) % MOD;

        ans = ans - 2*k - 2;

        ans = ans*k % MOD;
        ans = ans*invkm13 % MOD;
        while(ans<0)ans+=MOD;
        cout<<ans<<"\n";
    }
    return 0;
}