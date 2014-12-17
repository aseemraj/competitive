#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007;

map<pair<ll, ll>, int> ans;

ll find_ans(ll a, ll b, ll c, ll d)
{
    if ( b == 0 && d == 0 ) return 1;
    if ( b == 0 || d == 0 ) return 0;
    if (ans.find(make_pair(b, d)) != ans.end()) {
        return ans[make_pair(b, d)];
    }
    ll tans = 0;
    for (int k = 0; k * c + d % c <= b; k++) {
        ll a0 = k * c + d % c;
        if ((b - a0) % a == 0 && a0 <= b)
            tans += find_ans(a, (b - a0) / a, c, (d - a0) / c);
    }
    ans[make_pair(b, d)] = tans % MOD;
    return tans % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll t, a, b;
    cin>>t>>a>>b;
    if(t==1&&a==1)
    {
        if(b==1)cout<<"inf\n";
        else cout<<"0\n";
        return 0;
    }
    ans.clear();
    cout<<find_ans(t, a, a, b)<<endl;
    return 0;
}
