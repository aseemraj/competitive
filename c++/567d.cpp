/*
Author: aseemraj
Problem: 567d
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

set<int> s1, s2;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, a, m, x, maxships, l, r, ans;
    cin>>n>>k>>a>>m;
    s1.insert(0), s1.insert(n+1);
    s2.insert(0), s2.insert(-n-1);
    maxships = (n+1)/(a+1);
    bool f = 0;
    loop(i, 0, m)
    {
        cin>>x;
        if(f)continue;
        l = -*(s2.upper_bound(-x));
        r = *(s1.upper_bound(x));
        maxships = maxships - (r-l)/(a+1) + (x-l)/(a+1) + (r-x)/(a+1);
        if(maxships < k)
            ans = i+1, f = 1;
        s1.insert(x);
        s2.insert(-x);
    }
    if(f)
        cout<<ans<<"\n";
    else cout<<"-1\n";
    
    return 0;
}
