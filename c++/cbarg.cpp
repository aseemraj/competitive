/*
Author: aseemraj
Problem: cbarg
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
    int t, n;
    ll m, alloc, total;
    cin>>t;
    while(t--)
    {
        alloc = 0;
        total = 0;
        cin>>n;
        loop(i, 0, n)
        {
            cin>>m;
            if(alloc>m)
                alloc -= alloc-m;
            else
            {
                total += m-alloc;
                alloc += m-alloc;
            }
        }
        cout<<total<<"\n";
    }
    
    return 0;
}
