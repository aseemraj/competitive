#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int h[105][105];
int lef[105][105];
int righ[105][105];
int up[105][105];
int down[105][105];

int main()
{
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin>>h[i][j];
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = 0;
            for (int j = 0; j < m; j++)
                lef[i][j] = mx, mx = max(mx, h[i][j]);
        }
        for (int i = 0; i < n; i++)
        {
            mx = 0;
            for (int j = m-1; j >= 0; j--)
                righ[i][j] = mx, mx = max(mx, h[i][j]);
        }
        for (int j = 0; j < m; j++)
        {
            mx = 0;
            for (int i = 0; i < n; i++)
                up[j][i] = mx, mx = max(mx, h[i][j]);
        }
        for (int j = 0; j < m; j++)
        {
            mx = 0;
            for (int i = n-1; i >= 0; i--)
                down[j][i] = mx, mx = max(mx, h[i][j]);
        }
        int ans = 0, r;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                r = max(0, min(lef[i][j], min(righ[i][j], min(up[j][i], down[j][i]))) - h[i][j]);
                cout<<r<<' ';
                ans += r;
            }
            cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}