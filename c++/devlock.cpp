/*
Author: aseemraj
Problem: CHPUZZLE
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
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

const int MOD = 998244353;

int sum(int n)
{
    int sum=0;
    while(n)sum+=n%10, n/=10;
    return sum;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p, mm, c, i;
    cin>>n>>p>>mm;

    loop(m, 0, mm+1)
    {
        c = 0;
        for(i=0; i<=n; i+=p)
            if(sum(i)<=m)c++;
        cout<<c<<' ';
    }

    return 0;
}