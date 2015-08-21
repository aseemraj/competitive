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
    int x, y, z, q, t;
    cin>>x>>y>>z;
    int health[x+1][y+1][z+1];
    int deadonfloor[z+1];
    loop(i, 0, x)
        loop(j, 0, y)
            loop(k, 0, z)
                cin>>health[i][j][k];
    cin>>q;
    while(q--)
    {
        cin>>t;
        if(t == 1)
        {

        }
        else if(t == 2)
        {

        }
        else
        {
            
        }
    }
    return 0;
}
