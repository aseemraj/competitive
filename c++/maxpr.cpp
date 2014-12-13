#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
#define MAX 1000000007
using namespace std;
ll a[200005];
ll modulo(ll a,ll b,ll c){ll x=1,y=a;while(b>0){if(b%2 == 1)x=(x*y)%c;y=(y*y)%c;b=b>>1;}return x%c;}
int main()
{
    ios_base::sync_with_stdio(false);
    int t, diff, x, y;
    ll n, ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 1;    // for no element selected is an AP too
        loop(i, 0, n) cin>>a[i];
        ll dp[102][102] = {{0}};
        ll freq[102] = {0};
        loop(i, 0, n)
        {
            x = a[i];
            loop(j, 1, 101)
            {
                diff = x-j;
                if(diff==0)         // if same elements like 1 1 1 1 1
                    dp[x][j] = (2*dp[x][j]+1)%MAX;
                else
                {
                    if(j-diff>=0 && j-diff<=100)   // if there exists an element before the previous element
                        dp[x][j] = (dp[x][j] + freq[j] + dp[j][j-diff])%MAX;
                    else            // if there don't exist an element before the previous element
                        dp[x][j] = (dp[x][j] + freq[j])%MAX;
                }
            }
            freq[a[i]]++;
        }
        loop(i, 1, 101)
            loop(j, 1, 101)
                ans = (ans + dp[i][j])%MAX;
        cout<<((modulo(2, n, MAX) - ans)%MAX + MAX)%MAX<<endl;
    }
    return 0;
}
