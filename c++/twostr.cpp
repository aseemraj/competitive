/*
Author: aseemraj
Problem: twostr
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t, n;
    string a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        n = a.length();
        bool f = 1;
        loop(i, 0, n)
        {
            if(a[i] == b[i] || a[i] == '?' || b[i] == '?')
                continue;
            else
            {
                f = 0;
                break;
            }
        }
        if(f)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
