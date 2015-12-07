/*
Author: aseemraj
Problem: devasena
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
const int MOD = 1000000007;
ll a[100005];
ll pt[100005][20];
ll powmod(ll a,ll b,ll c)
{
    ll x=1,y=a;
    while(b>0){if(b&1)x=(x*y)%c;y=(y*y)%c;b=b>>1;}return x%c;
}

void pfactorize(int n)
{
    int c, i;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            c = 0;
            while(n%i == 0)
            {
                n /= i;
                c++;
            }
            pt[i][c]++;
            pt[i][0]++;
        }
    }
    if(n > 1)
    {
        pt[n][1]++, pt[n][0]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    ll fans, ans, sum;
    cin>>t;
    while(t--)
    {
        loop(i, 0, 100005)
            loop(j, 0, 20)
                pt[i][j] = 0;
        cin>>n;
        loop(i, 0, n)
        {
            cin>>a[i];
            pfactorize(a[i]);
        }
        fans = 1;
        loop(i, 2, 100005)
        {
            sum = pt[i][0];
            if(sum == 0)
                continue;
            ans = 0;
            loop(j, 1, 20)
            {
                ans = ans + powmod(2, sum, MOD-1) - 1;
                sum -= pt[i][j];
            }
            ans = ((ans%(MOD-1)) + MOD-1) % (MOD-1);
            fans = (fans*powmod(i, ans, MOD)) % MOD;
        }
        cout<<fans<<"\n";
    }
    return 0;
}
