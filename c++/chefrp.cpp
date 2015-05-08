/*
Author: aseemraj
Problem: chefrp
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
    int t, n, x, sum;
    cin>>t;
    while(t--)
    {
        bool canfind = true;
        sum = 0;
        cin>>n;
        int mn = INT_MAX;
        loop(i, 0, n)
        {
            cin>>x;
            if(x<2)canfind = false;
            sum += x;
            mn = min(mn, x);
        }
        if(canfind)
            cout<<sum-mn+2<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}