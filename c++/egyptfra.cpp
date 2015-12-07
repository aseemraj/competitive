/*
Author: aseemraj
Problem: 
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

int main()
{
    ios_base::sync_with_stdio(0);
    ll a, b, x, y, t;
    cin>>a>>b;
    while(a != 1 || b != 1)
    {
        x = a, y = b;
        while(x > 1)
        {
            t = y/x + 1;
            cout<<t<<' ';
            x = (-y)%x;
            y = y*t;
        }
        cout<<y;
        cout<<"\n";
        cin>>a>>b;
    }

    return 0;
}
