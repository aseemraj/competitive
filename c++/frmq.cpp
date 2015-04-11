/*
Author: aseemraj
Problem: FRMQ
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
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

int arr[100005];
int logtwo[100005];
int M[30][100005];
int pow2[30];
void init(int n)
{
    int i, j;
    pow2[0] = 1;
    loop(i, 1, 30)
        pow2[i] = pow2[i - 1] << 1;
    logtwo[1] = 0;
    loop(i, 2, n+1)
        logtwo[i] = logtwo[i >> 1] + 1;
    loop(i, 0, n)
        M[0][i] = i;
    for(j = 1; pow2[j] < n; ++j)
        for(i = 0; i + pow2[j] <= n; ++i)
            M[j][i] = arr[M[j-1][i]] >= arr[M[j - 1][i + (pow2[j - 1])]] ? M[j - 1][i] : M[j - 1][i + (pow2[j - 1])];
}
int query(int i, int j)
{
    int k = logtwo[j - i];
    return arr[M[k][i]] >= arr[M[k][j - (pow2[k]) + 1]] ? M[k][i] : M[k][j - (pow2[k]) + 1];
}
int main()
{
    int n, i, m, x, y;
    scanf("%d", &n);
    loop(i, 0, n)
        scanf("%d", &arr[i]);
    init(n);
    scanf("%d %d %d", &m, &x, &y);
    ll ans = 0;
    while(m--)
    {
        ans += arr[query(min(x, y), max(x, y))];
        x = x + 7;
        if(x>=n-1)x%=n-1;
        y = y + 11;
        if(y>=n)y%=n;
    }
    printf("%lld\n", ans);
    return 0;
}