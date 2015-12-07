/*
Author: aseemraj
Problem:bakuman
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
    int t, n, k;
    string a, b;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(n==0)
        {
            if(k>0)cout<<"No\n";
            else cout<<"Yes\n";
            continue;
        }
        cin>>a>>b;
        int dif = abs(a[0] - b[0]);
        int cnt = 1, mx = 0;
        loop(i, 1, n)
        {
            if(abs(a[i] - b[i]) == dif)
                cnt++;
            else
            {
                mx = max(cnt, mx);
                dif = abs(a[i] - b[i]);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
        if(mx >= k)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
