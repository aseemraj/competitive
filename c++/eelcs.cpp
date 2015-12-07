/*
Author: aseemraj
Problem: eelcs
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

int LCS(string a, string b)
{
    int n = a.length(), m = b.length();
    int dp[n+1][m+1];
    
    loop(i, 0, n+1)
        dp[i][0] = 0;
    loop(i, 0, m+1)
        dp[0][i] = 0;
    
    loop(i, 1, n+1)
    {
        loop(j, 1, m+1)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = max(max(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1] + 1);
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0);
    string a, b;
    cin>>a>>b;
    cout<<LCS(a, b)<<"\n";
    return 0;
}
