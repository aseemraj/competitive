/*
Author: aseemraj
Problem: 544C
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
ll dp[505][505];
ll a[505];
int main()
{
    ios_base::sync_with_stdio(0);
    ll n, m, b, mod;
    cin>>n>>m>>b>>mod;
    loop(i, 0, n)cin>>a[i];
    dp[0][0] = 1;
    loop(i, 0, n)
        loop(j, 0, m)
            loop(k, 0, b-a[i]+1)
                dp[j+1][k+a[i]] = (dp[j+1][k+a[i]]+dp[j][k]) % mod;
    ll res = 0;
    loop(i, 0, b+1)
        res = (res+dp[m][i]) % mod;
    cout<<res<<"\n";
    return 0;
}