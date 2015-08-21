/*
Author: aseemraj
Problem: lckyst
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
    int n, c;
    cin>>n;
    ll a, x;
    loop(i, 0, n)
    {
        cin>>a;
        c = 0; // number of 5s as a factor of a
        x = a;
        while(x%10==0)x/=10;
        while(x%5==0)
        {
            x /= 5;
            c++;
        }
        if(c&1)c++;
        cout<<a*(1LL<<c)<<"\n";
    }    
    return 0;
}
