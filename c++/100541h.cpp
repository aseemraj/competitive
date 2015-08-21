/*
Author: aseemraj
Problem: 100541h
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

int main()
{
    ios_base::sync_with_stdio(0);
    int t, sz;
    ll m, n, l, sq, w, h, k, area, u, x;
    VLL factors;
    cin>>t;
    while(t--)
    {
        factors.clear();
        cin>>m>>n>>l;
        if(l < m*n)
        {
            cout<<1<<"\n";
            continue;
        }
        sq = sqrt(l);
        loop(i, 1, sq+1)
        {
            if(l%i == 0)
            {
                factors.PB(i);
                factors.PB(l/i);
            }
        }
        sort(ALL(factors));

        sz = factors.size();
        bool ans = 0;
        area = 1e13;
        loop(i, 0, sz)
        {
            w = factors[i];
            if(w>n)break;
            loop(j, 0, sz)
            {
                h = factors[j];
                // cout<<"w: "<<w<<", h: "<<h<<"\n";
                if(h>m)break;
                if(((2*l) % (w*h) != 0)) continue;
                k = (2*l)/(w*h) - (h-1)*n - (w-1);
                if(k&1)continue;
                k = k/2;
                u = k/n;
                x = k%n;
                if(u + h <= m && x + w <= n)
                {
                    // cout<<"k: "<<k<<", u: "<<u<<", x: "<<x<<", w: "<<w<<", h: "<<h<<"\n";
                    area = min(area, w*h);
                    ans = 1;
                }
            }
        }
        if(ans)cout<<area<<"\n";
        else cout<<"-1\n";
    }
    
    return 0;
}
