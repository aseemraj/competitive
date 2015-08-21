/*
Author: aseemraj
Problem: fibosum
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
typedef unsigned long long ull;
using namespace std;

const int MOD = 1000000007;
ull a[2][2];
void mulmat(ull x[2][2], ull y[2][2])
{
    a[0][0] = (((x[0][0]*y[0][0]) % MOD) + ((x[0][1]*y[1][0]) % MOD)) % MOD;
    a[0][1] = (((x[0][0]*y[0][1]) % MOD) + ((x[0][1]*y[1][1]) % MOD)) % MOD;
    a[1][0] = (((x[1][0]*y[0][0]) % MOD) + ((x[1][1]*y[1][0]) % MOD)) % MOD;
    a[1][1] = (((x[1][0]*y[0][1]) % MOD) + ((x[1][1]*y[1][1]) % MOD)) % MOD;
}

ull powmat(ull n)
{
    ull x[2][2] = {{1, 0}, {0, 1}};
    ull y[2][2] = {{1, 1}, {1, 0}};
    while(n)
    {
        if(n&1)
        {
            mulmat(x, y);
            x[0][0] = a[0][0];
            x[0][1] = a[0][1];
            x[1][0] = a[1][0];
            x[1][1] = a[1][1];
        }
        mulmat(y, y);
        y[0][0] = a[0][0];
        y[0][1] = a[0][1];
        y[1][0] = a[1][0];
        y[1][1] = a[1][1];
        n >>= 1;
    }
    return x[0][1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m;
    cin>>t;
    while(t--)
    {
        // using the fact that S[n] = sum of fibonacci series from
        // first to nth fibonacci number = F[n+2] - 1
        cin>>n>>m;
        cout<<(powmat(m + 2) - powmat(n + 1) + MOD) % MOD<<"\n";
    }
    
    return 0;
}
