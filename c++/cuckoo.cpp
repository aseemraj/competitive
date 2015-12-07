/*
Author: aseemraj
Problem: cuckoo
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
    int t, n, m, cur, r, pos;
    bool placed, f;
    cin>>t;
    while(t--)
    {
        f = 0;
        cin>>m>>n;
        int tab[n], h1[m], h2[m];
        loop(i, 0, n)
            tab[i] = -1;

        loop(i, 0, m)
            cin>>h1[i]>>h2[i];
        loop(i, 0, m)
        {
            if(tab[h1[i]] == -1)
                tab[h1[i]] = i;
            else if(tab[h2[i]] == -1)
                tab[h2[i]] = i;
            else
            {
                pos = h1[i];
                placed = 0;
                cur = i;
                while(!placed)
                {
                    r = tab[pos];
                    tab[pos] = cur;

                    if(r == -1)
                        placed = 1;

                    pos = h1[r] + h2[r] - pos;
                    cur = r;

                    if(cur == i && pos == h1[cur])
                    {
                        placed = 1;
                        f = 1;
                    }
                }
            }
            if(f)break;
        }
        if(f)
            cout<<"rehash necessary\n";
        else
            cout<<"successful hashing\n";
    }
    return 0;
}
