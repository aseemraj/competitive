#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;
int n, m, y[500][500], b[500][500], ysum[501][501], bsum[501][501], dp[501][501];
int main()
{
    int i, j;
    while(1)
    {
        cin>>n>>m;
        if(n == 0)
            break;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                cin>>y[i][j];

        for(i=0; i < n; i++)
            for(j=0; j < m; j++)
                cin>>b[i][j];

        for(i=0; i <= n; i++)
            ysum[i][0]=0;
        for(i=1; i <= n; i++)
            for(j=1; j <= m; j++)
                ysum[i][j] = ysum[i][j-1] + y[i-1][j-1];

        for(i = 0; i <= m; i++)
            bsum[0][i] = 0;

        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                bsum[i][j] = bsum[i-1][j] + b[i-1][j-1];

        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                dp[i][j] = max(dp[i-1][j] + ysum[i][j], dp[i][j-1] + bsum[i][j]);

        cout<<dp[n][m]<<endl;
    }
    return 0;
}
