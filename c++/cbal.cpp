/*
Author: aseemraj
Problem: sez
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

string p;
ll fastexp(ll a, ll b){ll x=1,y=a;while(b>0){if(b&1)x=x*y;y=y*y;b=b>>1;}return x;}
ll query(int l, int r, int type)
{
    ll ret = 0;
    loop(i, l, r+1)
    {
        int mask = 1<<(p[i]-'a');
        loop(j, i+1, r+1)
        {
            int v = 1<<(p[j]-'a');
            mask = mask^v;
            if(mask == 0)
                ret += fastexp(j-i+1, type);
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, q, a, b, x, y, type, n, temp, val, l, r;
    cin>>t;
    while(t--)
    {
        cin>>p;
        cin>>q;
        n = p.length();
        a = b = 0;
        while(q--)
        {
            cin>>x>>y>>type;
            l = (x+a) % n+1;
            r = (y+b) % n+1;
            if(l>r)
            {
                temp = l;
                l = r;
                r = temp;
            }
            val = query(l-1, r-1, type);
            cout<<val<<"\n";
            a = b;
            b = val;
        }
    }
    return 0;
}

