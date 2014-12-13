#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
using namespace std;
int dp[100002][102];
int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, q, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        int a[n+1];
        loop(i, 1, n+1)
            cin>>a[i];
        while(q--)
        {
            cin>>m;
            loop(i, 0, n+1)
                dp[i][0] = 1;
            loop(i, 0, m+1)
                dp[0][i]=0;
            loop(i, 1, n+1)
            {
                loop(j, 1, m+1)
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i]];
                }
            }
            cout<<dp[n][m]<<endl;
        }
    }
    return 0;
}
