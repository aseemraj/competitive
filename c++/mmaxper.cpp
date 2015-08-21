/*
Author: aseemraj
Problem: MMAXPER
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

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n], b[n];

    loop(i, 0, n)cin>>a[i]>>b[i];

    ll dp[n][2];

    dp[0][0] = a[0];
    dp[0][1] = b[0];

    loop(i, 1, n)
    {
        dp[i][0] = a[i] + max(dp[i-1][0] + abs(b[i] - b[i-1]), dp[i-1][1] + abs(b[i] - a[i-1]));
        dp[i][1] = b[i] + max(dp[i-1][0] + abs(a[i] - b[i-1]), dp[i-1][1] + abs(a[i] - a[i-1]));
    }

    cout<<max(dp[n-1][0], dp[n-1][1])<<"\n";
    
    return 0;
}
