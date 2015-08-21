/*
Author: aseemraj
Problem: 
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

int dp[1020][1020];
int a[1020];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, f, s, test = 1;
    cin>>n;

    while(n)
    {
        loop(i, 0, n)
        {
            cin>>a[i];
        }

        loop(i, 0, n-1)
        {
            dp[i][i+1] = abs(a[i] - a[i+1]);
        }

        for(int k = 3; k <= n-1; k += 2)
        {
            loop(i, 0, n-k)
            {
                if(a[i+1] < a[i+k])
                    f = dp[i+1][i+k-1] + a[i] - a[i+k];
                else if(a[i+1] > a[i+k])
                    f = dp[i+2][i+k] + a[i] - a[i+1];
                else
                    f = a[i] - a[i+1] + dp[i+2][i+k];

                if(a[i] < a[i+k-1])
                    s = dp[i][i+k-2] + a[i+k] - a[i+k-1];
                else if(a[i] > a[i+k-1])
                    s = dp[i+1][i+k-1] + a[i+k] - a[i];
                else
                    s = a[i+k] - a[i] + dp[i+1][i+k-1];

                dp[i][i+k] = max(f, s);
            }
        }

        cout<<"In game "<<test<<", the greedy strategy might lose by as many as "<<dp[0][n-1]<<" points.\n";
        test++;
        cin>>n;
    }

    
    return 0;
}
