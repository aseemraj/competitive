#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
ll lg(ll n){ll c = 0;while(n>>=1)c++;return c;}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, p;
    ll k;
    long double x, n, d, ans;
    cin>>t;
    while(t--)
    {
        cin>>x>>k;
        p = lg(k);
        n = ((k&((1LL<<p)-1))<<1)+1;
        d = 1LL<<(p+1);
        ans = (n/d)*x;
        cout<<fixed<<setprecision(8)<<ans<<endl;
    }
    return 0;
}
