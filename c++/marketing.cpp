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
const int MAXN = 1<<15;
const int SQMAXN = 182;
const int INF = MAXN+1;
int dp[MAXN];

int main()
{
    int n, k, t, c;
    dp[0] = 0;
    for(int i = 1; i <= SQMAXN; i++)
        dp[i*i] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(dp[i] > 0) continue;
        dp[i] = INF;
        for(int j = 1; j*j < i; j++)
            dp[i] = min(dp[i], dp[i-j*j] + 1);
    }

    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &k);
        printf("%d\n", k*dp[n]);
    }
    return 0;
}
