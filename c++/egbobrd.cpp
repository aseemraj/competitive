/*
Author: aseemraj
Problem: egbobrd
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
    int t;
    ll n, k, a, curLoaf, loafs;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        curLoaf = loafs = 1;
        loop(i, 0, n)
        {
            if(curLoaf < k && curLoaf > 0)
                curLoaf++;
            if(curLoaf == k)
                loafs++, curLoaf = 0;

            cin>>a;
            if(curLoaf + a <= k)
                curLoaf += a;
            else
            {
                curLoaf += a - k;
            }
        }
        if(curLoaf == k)
            loafs++, curLoaf = 0;
        cout<<loafs<<"\n";
    }

    return 0;
}
