/*
Author: aseemraj
Problem: icandies
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
    int cases, t = 1, n, f;
    cin>>cases;
    while(cases--)
    {
        cin>>n;
        f = -1;
        for(int i = 5; i < n; i += 5)
        {
            if((n-i)%3 == 0)
            {
                f = n-i;
                break;
            }
        }
        cout<<"Case "<<t++<<": "<<f<<"\n";
    }
    return 0;
}
