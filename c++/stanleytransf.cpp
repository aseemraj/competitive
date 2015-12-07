/*
Author: aseemraj
Problem: stanleytransf
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
    int t, n, m, a, b, c, cost, d;
    string x, u;
    cin>>t;
    while(t--)
    {
        cin>>x>>u>>a>>b>>c;
        cost = 0;
        int nc[200][2] = {{0}};

        n = x.length();
        m = u.length();

        loop(i, 0, n)
            nc[x[i]][0]++;
        loop(i, 0, m)
            nc[u[i]][1]++;

        int rem[2] = {0};
        loop(i, 97, 123)
        {
            d = min(nc[i][0], nc[i][1]);
            rem[0] += nc[i][0] - d;
            rem[1] += nc[i][1] - d;
        }
        if(rem[0] > rem[1])
            cost += a*(rem[0] - rem[1]);
        else
            cost += b*(rem[1] - rem[0]);

        cost += min(a+b, c)*min(rem[0], rem[1]);
        cout<<cost<<"\n";
    }
    return 0;
}
