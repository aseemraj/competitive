#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll dp[10000005];
ll fastexp(ll a, ll b){ll x=1;while(b){if(b&1)x=(x*a)%MOD;a=(a*a)%MOD;b>>=1;}return x;}
int main()
{
    ios_base::sync_with_stdio(0);
    ll t, n, m, l, r, e, s, c, ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>r;
        e = m;
        c = 1;
        while(1)
        {
            s = e;
            e = m/(c+1);
            if(s==e)break;
            ans = fastexp(c, n);
            for(ll i=2*s; i<=m; i+=s)
            {
                ans = (ans-dp[i]);
                if(ans<0) ans = (ans+MOD)%MOD;
            }
            for(ll i=s; i>=e+1; i--)
                dp[i] = ans;
            c++;
        }
        for(ll i=s; i>=l; i--)
        {
            dp[i] = fastexp((m/i), n);
            for(ll j=2*i; j<=m; j+=i)
            {
                dp[i] = dp[i]-dp[j];
                if(dp[i]<0)
                    dp[i] = (dp[i]+MOD)%MOD;
            }
        }
        ll sum = 0;
        for(ll i=l; i<=r; i++)
        {
            sum = sum + dp[i];
            if(sum>=MOD)sum%=MOD;
        }
        cout<<sum<<endl;
    }
    return 0;
}
