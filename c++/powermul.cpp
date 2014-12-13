#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
ll hf[100005];
ll fastexp(ll a, ll b){ll x=1,y=a;while(b>0){if(b&1)x=x*y;y=y*y;b>>=1;}return x;}
ll fastexpmod(ll a, ll b, ll c){ll x=1,y=a;while(b>0){if(b&1)x=(x*y)%c;y=(y*y)%c;b>>=1;}return x%c;}
pair<ll, pair<ll,ll> > extendedEuclid(ll a, ll b)
{
    if(a==0)return make_pair(b, make_pair(0, 1));
    pair<int, pair<int, int> > p;
    p = extendedEuclid(b%a, a);
    return make_pair(p.first, make_pair(p.second.second-p.second.first*(b/a), p.second.first));
}
ll modinv(ll a, ll m){return(extendedEuclid(a,m).second.first+m)%m;}
ll gcd(ll a, ll b){if(a%b==0)return b;return gcd(b,a%b);}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, q, r;
    ll n, m, num, den;
    hf[0] = 1;
    hf[1] = 1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        ll ans = 1;
        ll cnt[505] = {0};
        if(n<=5)
        {
            loop(i, 2, n+1)
              ans*=fastexp(i, i);
            num=ans;
        }
        else
        {
            for(ll i=2;i<=n;i++)
            {
                if(i%m==0)
                {
                    cnt[i]=cnt[i-1];
                    ll tmp=i;
                    while(tmp%m==0)
                    {
                        tmp/=m;
                        cnt[i] += i;
                    }
                    hf[i]=(hf[i-1]*fastexpmod(tmp, i, m))%m;
                }
                else
                {
                    cnt[i]=cnt[i-1];
                    hf[i]=(hf[i-1]*fastexpmod(i, i, m))%m;
                }
            }
        }
        while(q--)
        {
            cin>>r;
            if(m==1){cout<<0<<endl;continue;}
            if(n<=5)
            {
                ans = num;
                loop(i, 2, r+1)ans/=fastexp(i, i);
                loop(i, 2, n-r+1)ans/=fastexp(i, i);
                cout<<ans%m<<endl;
                continue;
            }
            if(cnt[r]+cnt[n-r]<cnt[n])cout<<0<<endl;
            else cout<<(((hf[n]*fastexpmod(hf[r], m-2, m))%m)*fastexpmod(hf[n-r], m-2, m))%m<<endl;
        }
    }
    return 0;
}
