/*
Author: aseemraj
Problem: seqlcs
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

int a[20];

int CountOnes(int x)
{
    int cnt = 0;
    while(x)
    {
        x = x&(x-1);
        cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>l;
        set<VI> powerset;
        loop(i, 0, n)cin>>a[i];
        ll maxsets = (1<<n) - 1;
        loop(i, 0, maxsets+1)
        {
            if(CountOnes(i) == l)
            {
                k = 0;
                VI v;
                while((1<<k) <= i)
                {
                    if(i&(1<<k))
                    {
                        v.push_back(a[i]);
                    }
                    k++;
                }
                powerset.insert(v);
            }
        }
        
    }
    return 0;
}
