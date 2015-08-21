/*
Author: aseemraj
Problem: 559c
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

const int MAX = 200100;
const int mod = 1000000007;
int h, w, n;
ll val[MAX], invval[MAX];

ll powbitbin(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll fetch(int x, int y, int x2, int y2)
{
    int h = x2 - x;
    int w = y2 - y;
    ll ans = val[h + w];
    ans = (ans * invval[h]) % mod;
    ans = (ans * invval[w]) % mod;
    return ans;
}

struct node
{
    int x, y;
    bool operator < (node T) const
    {
        if (x == T.x) return y < T.y;
        return x < T.x;
    }
} a[MAX];

ll dp[MAX];

int main ()
{
    val[0] = 1;
    invval[0] = 1;
    loop(i, 1, 200005)
    {
        val[i] = (val[i - 1] * i) % mod;
        invval[i] = powbitbin(val[i], mod - 2);
    }
    cin>>h>>w>>n;

    loop(i, 1, n+1)
    {
        cin>>a[i].x>>a[i].y;
    }
    n++;
    a[n].x = h, a[n].y = w;

    sort(a + 1, a + 1 + n);
    memset(dp, 0, sizeof dp);
    
    loop(i, 1, n+1)
    {
        dp[i] = fetch(1, 1, a[i].x, a[i].y);
        loop(j, 1, i)
        {
            if (a[i].x >= a[j].x && a[i].y >= a[j].y)
            {
                dp[i] = (dp[i] - fetch(a[j].x, a[j].y, a[i].x, a[i].y) * dp[j]) % mod;
                if (dp[i] < 0) dp[i] += mod;
            }
        }
    }
    cout<<dp[n];

    return 0;
}