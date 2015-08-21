/*
Author: aseemraj
Problem: 559a
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
    ll a[6];
    loop(i, 0, 6)cin>>a[i];

    ll sum1 = a[0] + a[1] + a[2];
    sum1 *= sum1;
    ll sum2 = a[0]*a[0] + a[2]*a[2] + a[4]*a[4];
    cout<<sum1 - sum2<<"\n";
    
    return 0;
}
