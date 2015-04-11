/*
Author: aseemraj
Problem: CARLOS
*/

// DP state:
// dp[i][j] denotes answer to a[0...i] with letter at index i be made = atmost j

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

int dp[200005][205];
int a[200005];
int mn[205];
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, m, x, y;
    cin>>t;
    while(t--)
    {
        bool path[205][205] = {{0}};
        cin>>m>>k>>n;
        while(k--)
        {
            cin>>x>>y;
            if(x!=y)
            {
                path[x][y] = 1;
                path[y][x] = 1;
            }
        }
        loop(p, 1, m+1)
            loop(i, 1, m+1)
                loop(j, 1, m+1)
                    path[i][j] = path[j][i] = path[i][j] | (path[i][p] & path[j][p]);

        loop(i, 0, n)
            cin>>a[i];

        dp[0][0] = n+1;
        loop(j, 1, a[0])
        {
            if(path[a[0]][j])
                dp[0][j] = 1;
            else
                dp[0][j] = min(dp[0][j-1], n+1);
        }
        loop(j, a[0], m+1)dp[0][j] = 0;

        loop(i, 1, n)
        {
            dp[i][0] = n+1;
            loop(j, 1, m+1)
            {
                if(j==a[i]) dp[i][j] = dp[i-1][j];
                else if(path[a[i]][j]) dp[i][j] = min(dp[i][j-1], dp[i-1][j] + 1);
                else dp[i][j] = min(dp[i][j-1], n+1);
            }
        }
        int ans = n+1;
        loop(j, 1, m+1)
        {
            ans = min(ans, dp[n-1][j]);
        }
        if(ans==n+1)cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
    
    return 0;
}
