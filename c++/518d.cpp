/*
Author: aseemraj
Problem: 518D
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
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

double dp[2005][2005];

int main()
{
    ios_base::sync_with_stdio(0);

    int n, t;
    double p;
    cin>>n>>p>>t;

    loop(i, 0, t)dp[0][i] = 0;
    loop(i, 0, n)dp[i][0] = 0;

    loop(i, 2, n+1)
    {
        loop(j, 1, t+1)
        {
            dp[i][j] = p*dp[i-1][j-1] + (1-p)*dp[i][j-1];
        }
    }
    return 0;
}