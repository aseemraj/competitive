/*
Author: aseemraj
Problem: chapd
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
ll gcd(ll a, ll b){ll c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    ll a, b, d;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(b==1)
        {
            cout<<"Yes\n";
            continue;
        }
        d = gcd(a, b);
        if(d==1)
        {
            cout<<"No\n";
            continue;
        }
        while(b%d==0)
        {
            while(b%d==0)
                b /= d;
            if(b==1)
            {
                cout<<"Yes\n";
                break;
            }
            d = gcd(a, b);
            if(d==1)
            {
                cout<<"No\n";
                break;
            }
        }
    }
    return 0;
}