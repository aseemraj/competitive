/*
Author: aseemraj
Problem: svarea11
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
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
PI ivl[10005];
int main()
{
    ios_base::sync_with_stdio(0);
    int cases, t = 1, s, e, st, en, n, m;
    cin>>cases;
    while(cases--)
    {
        cin>>n>>m;
        loop(i, 0, m)
            cin>>ivl[i].S>>ivl[i].F;

        sort(ivl, ivl + m);
        s = e = 0;
        loop(i, 0, m)
        {
            st = ivl[i].S;
            en = ivl[i].F;
            if(st > e)
            {
                e = en;
                s++;
            }
        }

        cout<<"Plan "<<t++<<": ";
        if(s > n)cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
