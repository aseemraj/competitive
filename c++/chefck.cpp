/*
Author: aseemraj
Problem: chefck
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(ll i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
ll n, k;
ll arr[10000005];
ll minimum[10000005];

void init()
{
    ll x = arr[0];
    deque<ll> q;
    loop(i, 0, k)
    {
        while(!q.empty() && arr[i] <= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    loop(i, k, n)
    {
        minimum[i-k] = arr[q.front()];
        while(!q.empty() && arr[i] <= arr[q.back()])
            q.pop_back();
        while(!q.empty() && q.front() <= i-k)
            q.pop_front();
        q.push_back(i);
    }
    minimum[n-k] = arr[q.front()];
}

ll query(ll i, ll j)
{
    ll mn = minimum[i];
    if(j>=i+k)mn = min(mn, minimum[j-k+1]);
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll q, a, b, c, d, e, f, r, s, t, m, i, x, y;
    ll l1, la, lc, lm, d1, da, dc, dm, ans, prevsq;
    ll L, R;
    cin>>n>>k>>q;
    cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>arr[0];
    ll tpow = t;
    loop(i, 1, n)
    {
        tpow = (tpow*t)%s;
        prevsq = arr[i-1]*arr[i-1] % m;
        if(tpow <= r)
            arr[i] = (a*prevsq + b*arr[i-1] + c) % m;
        else
            arr[i] = (d*prevsq + e*arr[i-1] + f) % m;
    }

    init();
    ll sum = 0;
    ll prod = 1;

    cin>>l1>>la>>lc>>lm>>d1>>da>>dc>>dm;
    loop(i, 0, q)
    {
        l1 = (la*l1 + lc) % lm;
        d1 = (da*d1 + dc) % dm;
        L = l1 + 1;
        R = min(L + k - 1 + d1, n);
        L--, R--;
        ans = query(L, R);
        sum += ans;
        prod *= ans;
        if(prod>=MOD)prod%=MOD;
    }
    cout<<sum<<' '<<prod<<"\n";
    return 0;
}