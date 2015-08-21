/*
Author: aseemraj
Problem: 567c
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

ll a[200005];
map<ll, int> al, ar;
ll leftp[200005];
ll rightp[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    loop(i, 0, n)
    {
        cin>>a[i];
        if(a[i]%k == 0)
            leftp[i] = al[a[i]/k];
        al[a[i]]++;
    }
    rloop(i, 1, n)
    {
        if(a[i]%k == 0)
            rightp[i] = ar[a[i]*k];
        ar[a[i]]++;
    }

    ll ans = 0;
    loop(i, 0, n)
    {
        if(a[i]%k==0)
            ans += leftp[i] * rightp[i];
    }

    cout<<ans<<"\n";
    
    return 0;
}
