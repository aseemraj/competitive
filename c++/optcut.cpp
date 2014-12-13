#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int dp[102][102];
int minsq(int m, int n)
{
    if(m==n)return 1;
    if(m<n)
      swap(m, n);
    if(dp[m][n])
        return dp[m][n];
    int mn = INT_MAX;
    for(int i=1;2*i<=n;i++)
        mn = min(mn, minsq(m, i) + minsq(m, n-i));
    for(int i=1;2*i<=m;i++)
        mn = min(mn, minsq(i, n) + minsq(m-i, n));
    return dp[m][n] = mn;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, m, n;
    cin>>t;
    while(t--)
    {
      cin>>m>>n;
      cout<<minsq(m, n)<<endl;
    }
    return 0;
}
