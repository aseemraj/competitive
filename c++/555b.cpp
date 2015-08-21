/*
Author: aseemraj
Problem: 555b
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

const int MAX = 200005;
int n, m;
PLL a[MAX], p[MAX];
P(PLL, int) seg[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;

    loop(i, 0, n)
        cin>>a[i].F>>a[i].S;
    loop(i, 1, n)
        seg[i] = make_pair(make_pair(a[i].F - a[i-1].S, a[i].S - a[i-1].F), i-1);

    sort(seg)
    
    loop(i, 0, m)
    {

    }
    sort(a, a + m);



    return 0;
}
