/*
Author: aseemraj
Problem: xorgrid
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

int n, ans, maxans;
ll b[20][20];

void move(int x, int y)
{
    ans = ans^b[x][y];
    if(y<n)
    {
        move(x, y+1);
    }
    else if(x<n)
    {
        move(x+1, y);
    }
    else
    {
        maxans = max(ans, maxans);
    }
    ans = ans^b[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    loop(i, 1, n+1)loop(j, 1, n+1)cin>>b[i][j];
    move(1, 1);
    cout<<maxans<<"\n";
    return 0;
}
