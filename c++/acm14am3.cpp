/*
Author: aseemraj
Problem: launch tower
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

int dp[20005][505];

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int n = s.length(), q, m, l, sum, md;
    cin>>q;
    while(q--)
    {
        cin>>m>>l;
        memset(dp, 0, sizeof dp);
        sum = 0;
        loop(i, 0, n)
        {
            dp[i+1][(s[i] - 48) % m]++;
            loop(j, 0, m)
            {
                md = (j*10 + s[i] - 48) % m;
                dp[i+1][md] += dp[i][j];
            }
        }

        loop(i, 1, n+1)
            sum += dp[i][l];

        cout<<sum<<"\n";
    }

    return 0;
}
