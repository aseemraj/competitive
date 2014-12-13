#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
int dp[250001][250001];
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string a, b;
    cin>>b>>a;
    int m = a.size();
    int n = b.size();
    int ans = 0, ind = max(m, n);
    loop(i, 0, m+1)
    {
        loop(j, 0, n+1)
        {
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j]>ans)
                {
                    ans = max(ans, dp[i][j]);
                    ind = min(i, ind);
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    string lcs="";
    loop(i, ind-1, ans)
        lcs = lcs + a[i];
    if(lcs.size()>0)
        cout<<lcs<<endl<<ans<<endl;
    else
        cout<<0<<endl;
    return 0;
}
