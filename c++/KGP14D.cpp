#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, k;
    cin>>t;
    loop(tt, 1, t+1)
    {
        cin>>k;
        pair<int,int> depdur[k];
        int dur[k];
        loop(i, 0, k)cin>>depdur[i].second;
        loop(i, 0, k){cin>>depdur[i].first;}
        sort(depdur, depdur+k);
        int dp[101][1441] = {{0}};
        loop(i, 1, k+1)
        {
            loop(j, 0, 1441)
            {
                dp[i][j] = dp[i-1][j] + 1;
                if(j + depdur[i-1].second+30<=depdur[i-1].first)
                    dp[i][j] = min(dp[i][j], dp[i-1][j+depdur[i-1].second]);
            }
        }
        cout<<"Case "<<tt<<": "<<dp[k][1440]<<endl;
    }
    return 0;
}
