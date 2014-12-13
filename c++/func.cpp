#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
#define MAX 1000000007
using namespace std;
ll sum[10005];
int main()
{
    ios_base::sync_with_stdio(false);
    int t, q;
    ll n, x, k, c, total;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        ll a[n+1];
        a[0] = 0;
        sum[0] = 0;
        loop(i, 1, n+1)
        {
            cin>>a[i];
            sum[i] = (sum[i-1] + a[i])%MAX;
        }
        while(q--)
        {
            cin>>x;
            k = 1;
            c = 0;
            total = 0;
            while(k<=x){k = k<<1;c++;}
            c = min(c, n+1);
            total = ((x%MAX)*a[1])%MAX;
            loop(i, 2, c) total = (total+ (ll)(pow(10, log10(x)/i))*a[i])%MAX;
            total = (((sum[n] - sum[c-1] + total)%MAX)+MAX)%MAX;
            if(q==0) cout<<total;
            else cout<<total<<' ';
        }
        cout<<endl;
    }
    return 0;
}
