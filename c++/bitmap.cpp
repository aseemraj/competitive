/*
Author: aseemraj
Problem: BITMAP
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
PI nodes[200][200];

int n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    string row;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        loop(i, 0, n)
        {
            cin>>row;
            loop(j, 0, m)
                color[i][j] = row[j]-48;
        }

    return 0;
}
