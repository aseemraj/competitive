#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define ll long long
using namespace std;

const int MAX = 1001;

char a[MAX], b[MAX];
int M, N;
int dp[MAX][MAX];

int main(void)
{
    int k, i, j;
    while(1)
    {
        cin>>k;
        if(!k)
            break;
        memset(dp, 0, sizeof(dp));
        scanf("%s", a+1);
        scanf("%s", b+1);

        M = strlen(a + 1);
        N = strlen(b + 1);
        int t;
        for(i=k;i<=M;i++)
        {
            for(j=k;j<=N;j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                for(t=0;t<=i;t++)
                {
                    if(t>=k)
                        dp[i][j] = max(dp[i][j], dp[i-t][j-t] + t);
                    if(a[i-t] != b[j-t])
                        break;
                }
            }
        }
        cout<<dp[M][N]<<endl;
    }
    return 0;
}
