/*
Author: aseemraj
Problem: stdytab
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

// DP state definition:
// dp[i][j] stores the number of different steady tables
// if sum of the elements of the ith row is at most j
// so we need to find dp[n][m]
ll dp[2005][2005];
ll nCr[4005][4005];

const int MOD = 1000000000;
void populateNCR()
{
    loop(i, 0, 4005)nCr[i][0]=1;
    loop(i, 1, 4005)
    {
        loop(j, 1, i+1)
        {
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
            if(nCr[i][j]>=MOD)nCr[i][j]-=MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    populateNCR();
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        loop(i, 0, n+1)
            dp[i][0] = 1;
        loop(i, 0, m+1)
            dp[0][i] = 1;
        loop(i, 1, n+1)
        {
            loop(j, 1, m+1)
            {
                dp[i][j] = dp[i][j-1] + ((nCr[m+j-1][j] * dp[i-1][j]) % MOD);
                if(dp[i][j]>=MOD)dp[i][j]-=MOD;
            }
        }
        cout<<dp[n][m]<<"\n";
    }
    return 0;
}
