#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll dp[105][105];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    ll a[n];
    loop(i, 0, n)cin>>a[i];
    loop(i, 0, n-1)
        if(a[i]+a[i+1]==0&&a[i]<0)
            dp[i][i+1] = 1;
    loop(j, 2, n)
    {
        loop(i, 0, n-j)
        {
            if(a[i]+a[j+i]==0 && a[i]<0)
                dp[i][j+i]=(2*dp[i+1][j+i-1]+1)%MOD;
            else
                dp[i][j+i]=dp[i+1][j+i-1];
            loop(k, i+1, j+i)
            {
                if(a[i]+a[k]==0&&a[i]<0)
                {
                    if(k==i+1)
                        dp[i][j+i] = (dp[i][j+i] + 1 + dp[k+1][j+i])%MOD;
                    else if(k==j+i-1)
                        dp[i][j+i] = (dp[i][j+i] + 1 + dp[i+1][k-1])%MOD;
                    else if(k>i+1&&k<j+i-1)
                        dp[i][j+i] = (dp[i][j+i] + dp[i+1][k-1] + 1 + (dp[i+1][k-1]+1)*dp[k+1][j+i])%MOD;
                }
                if(a[j+i]+a[k]==0&&a[k]<0)
                {
                    if(k==j+i-1)
                        dp[i][j+i] = (dp[i][j+i] + 1 + dp[i+1][k-1])%MOD;
                    else if(k==i+1)
                        dp[i][j+i] = (dp[i][j+i] + 1 + dp[k+1][j+i-1])%MOD;
                    else if(k>i+1&&k<j+i-1)
                        dp[i][j+i] = (dp[i][j+i] + dp[k+1][j+i-1] + 1 + (dp[k+1][j+i-1]+1)*dp[i+1][k-1])%MOD;
                }
            }
        }
    }
    cout<<dp[0][n-1]+1<<endl;
    return 0;
}
