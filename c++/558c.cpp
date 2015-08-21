/*
Author: aseemraj
Problem: Codeforces 558 C
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
    int n, d;
    cin>>n;
    int a[n];
    loop(i, 0, n)cin>>a[i];
    sort(a, a+n);
    int medi = (n-1)/2;

    loop(i, 0, n)
        while(((1<<17)&a[i]) == 0)
            a[i]<<=1;
    
    int k = 0;
    rloop(j, 0, 18)
    {
        int xr = (a[0]&(1<<j))>>j;
        cout<<"xr: "<<xr<<endl;
        loop(i, 0, n)
        {
            d = (a[i]&(1<<j))>>j;
            xr = !(xr^d);
            if(!xr)break;
        }
        cout<<d;
        if(xr==1)k = (k<<1) + d;
        else break;
    }
    cout<<k<<endl;

    return 0;
}
