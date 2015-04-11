/*
Author: aseemraj
Problem: STRQ
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define VI V(int)
#define VP V(PI)

typedef long long ll;
using namespace std;

ll dp[1000005][4][4];
ll cnt[1000005][4];

map<char, int> idx;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    idx['c'] = 0, idx['h'] = 1, idx['e'] = 2, idx['f'] = 3;
    int n, q, l, r, x, y;
    char a, b;
    string p;
    cin>>p>>q;
    n = p.size();

    loop(i, 0, 4){loop(j, 0, 4)dp[0][i][j]=0;}

    loop(i, 1, n+1)
    {
        loop(j, 0, 4)
        {
            loop(k, 0, 4)dp[i][j][k]=dp[i-1][j][k];
            cnt[i][j] = cnt[i-1][j];
        }
        x = idx[p[i-1]];
        cnt[i][x]++;
        loop(j, 0, 4)
            dp[i][j][x] += cnt[i][j];
    }

    while(q--)
    {
        cin>>a>>b>>l>>r;
        x = idx[a], y = idx[b];
        cout << dp[r][x][y] - dp[l-1][x][y] - cnt[l-1][x]*(cnt[r][y]-cnt[l-1][y]) << "\n";
    }
    return 0;
}