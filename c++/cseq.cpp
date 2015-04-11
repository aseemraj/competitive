/*
Author: aseemraj
Problem: CSEQ
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
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

const ll MOD = 1000003;
ll fact[1000010];

ll powmod(ll a,ll b,ll c){ll x=1,y=a;while(b>0){if(b&1)x=(x*y)%c;y=(y*y)%c;b=b>>1;}return x%c;}

void init()
{
    fact[0] = 1;
    loop(i, 1, MOD)
        fact[i] = (i*fact[i-1])%MOD;
}

ll mcnlucas(ll m, ll n, ll p)
{
    VLL mv, nv;
    ll mcn, q = m, a, b, fa, fb, fab, ans=1;
    while(q!=0)
    {
        mv.PB(q%p);
        q = q/p;
    }
    q = n;
    while(q!=0)
    {
        nv.PB(q%p);
        q = q/p;
    }
    while(mv.size()<nv.size())mv.push_back(0);
    while(nv.size()<mv.size())nv.push_back(0);
    
    int sz = mv.size();
    loop(i, 0, sz)
    {
        a = mv[i], b = nv[i];
        if(a<b)mcn=0;
        else if(a==b || b==0)mcn = 1;
        else
        {
            fa = fb = fab = 0;
            if(a<MOD)fa=fact[a];
            if(b<MOD)fb=fact[b];
            if(a-b<MOD)fab=fact[a-b];
            mcn = ((fa*powmod(fb, MOD-2, MOD))%MOD)*powmod(fab, MOD-2, MOD);
            // cout<<fa<<' '<<powmod(fb, MOD-2, MOD)<<' '<<powmod(fab, MOD-2, MOD)<<endl;
            mcn %= MOD;
        }
        ans = (ans*mcn)%p;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll t, n, l, r, a;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        a = n + r - l + 1;
        cout<<(mcnlucas(a, n, MOD) - 1 + MOD)%MOD<<"\n";
    }
    return 0;
}
