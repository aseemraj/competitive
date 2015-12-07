/*
Author: aseemraj
Problem: 
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
unsigned int dol[32][20];
unsigned int dollars(unsigned int n, int i, int j)
{
    if(n<12)
        return n;
    if(dol[i][j]==0)
        dol[i][j] = dollars(n/2, i+1, j) + dollars(n/3, i, j+1) + dollars(n/4, i+2, j);
    return dol[i][j];
}

int main()
{
    unsigned int n;
    while((scanf("%u",&n))!=EOF)
    {
        memset(dol, 0, sizeof dol);
        cout<<dollars(n, 0, 0)<<endl;
    }
    return 0;
}
