/*
Author: aseemraj
Problem: 100676e
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
    int t, n, loc, s;
    ll sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        VI a(n);
        loop(i, 0, n)cin>>a[i];
        sort(ALL(a));
        sum = 0;
        loop(i, 1, n)
        {
            s = a[i] - 32;
            loc = int(upper_bound(a.begin(), a.begin() + i, s) - a.begin());
            if(loc < i)
                sum += i - loc;
        }
        cout<<sum<<"\n";
    }
    
    return 0;
}
