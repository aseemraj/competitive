/*
Author: aseemraj
Problem: 100541i
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

string acm[1005];

int dp[1005][1005][4];

int main()
{
    ios_base::sync_with_stdio(0);
    int t, m, n;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        loop(i, 0, m)
            cin>>acm[i];

        loop(i, 0, n)
            dp[0][i][0] = acm[0][i] - 48;
        loop(i, 0, m)
            dp[i][n][0] = 0;

        loop(i, 1, m)
        {
            loop(j, 0, n)
            {
                if(acm[i][j] == '0')
                    dp[i][j][0] = 0;
                else if(acm[i-1][j] == '1')
                    dp[i][j][0] = 2 + dp[i-1][j+1][0];
                else dp[i][j][0] = 1;
            }
        }

        loop(i, 0, m)
            dp[i][0][1] = acm[i][0] - 48;
        loop(i, 1, n)
        {
            if(acm[0][i] == '0')dp[0][i][1] = 0;
            else dp[0][i][1] = 1 + acm[0][i-1] - 48;
        }

        loop(i, 1, m)
        {
            loop(j, 1, n)
            {
                if(acm[i][j] == '0')
                    dp[i][j][1] = 0;
                else if(acm[i][j-1] == '1')
                    dp[i][j][1] = 2 + dp[i-1][j-1][1];
                else dp[i][j][1] = 1;
            }
        }

        loop(i, 0, n)
            dp[m-1][i][2] = acm[m-1][i] - 48;
        rloop(i, 0, m-1)
        {
            if(acm[i][0] == '0') dp[i][0][2] = 0;
            else dp[i][0][2] = 1 + acm[i+1][0] - 48;
        }

        rloop(i, 0, m-1)
        {
            rloop(j, 1, n)
            {
                if(acm[i][j] == '0')
                    dp[i][j][2] = 0;
                else if(acm[i+1][j] == '1')
                    dp[i][j][2] = 2 + dp[i+1][j-1][2];
                else dp[i][j][2] = 1;
            }
        }

        loop(i, 0, m)
            dp[i][n-1][3] = acm[i][n-1] - 48;
        rloop(i, 0, n-1)
        {
            if(acm[m-1][i] == '0')dp[m-1][i][3] = 0;
            else dp[m-1][i][3] = 1 + acm[m-1][i+1] - 48;
        }

        rloop(i, 0, m-1)
        {
            rloop(j, 0, n-1)
            {
                if(acm[i][j] == '0')
                    dp[i][j][3] = 0;
                else if(acm[i][j+1] == '1')
                    dp[i][j][3] = 2 + dp[i+1][j+1][3];
                else dp[i][j][3] = 1;
            }
        }

        int mx = 0;
        loop(i, 0, m)
        {
            loop(j, 0, n)
            {
                mx = max(mx, dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3] - 3);
            }
        }
        cout<<mx<<"\n";
    }
    
    return 0;
}
