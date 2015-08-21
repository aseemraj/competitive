/*
Author: aseemraj
Problem: setdiff
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
ll powmod(ll a,ll b,ll c){ll x=1,y=a;while(b>0){if(b&1)x=(x*y)%c;y=(y*y)%c;b=b>>1;}return x%c;}
int main()
{
    ios_base::sync_with_stdio(0);
    ll t, n, sum, temp, k1, k2;
    ll inv2 = powmod(2, MOD-2, MOD);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n+1];
        a[0] = -1;
        loop(i, 1, n+1)cin>>a[i];
        sort(a, a+n+1);
        sum = 0;
        k1 = 1;
        k2 = powmod(2, n-1, MOD);
        loop(i, 1, n+1)
        {
            temp = (k1 - k2)*a[i];
            k1 = (k1<<1)%MOD;
            k2 = (k2*inv2)%MOD;
            sum = sum+temp % MOD;
        }
        while(sum<0)sum += MOD;
        cout<<sum%MOD<<"\n";
    }
    return 0;
}