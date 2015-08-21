/*
Author: aseemraj
Problem: another knapsack
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
    ll n, m, c;
    cin>>n>>m;
    if(n*(n+1)/2 < m)
    {
        cout<<"-1";
        return 0;
    }
    while(m>n)
    {
        c++;
        m = m - n;
        n--;
    }
    cout<<c+1;
    return 0;
}