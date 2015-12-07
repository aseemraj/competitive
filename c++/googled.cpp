/*
Author: aseemraj
Problem: googleD
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1e18;

ll grid[3005][3005];
ll memz[3005][3005];

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int cases, n;
    ll k, c, x;
    cin>>cases;
    for (int t = 1; t <= cases; t++)
    {
        cin>>n>>k>>c>>x;
        ll a[n+1], b[n+1];
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        for(int i = 1; i <= n; i++)
            cin>>b[i];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                grid[i][j] = (a[i]*i + b[j]*j + c) % x;
                memz[i][j] = 0;
            }

        ll ans = 0, val;

        for(int i = 1; i <= n; i++)
        {
            deque<int> dq;
            for(int j = 1; j < k; j++)
            {
                while(dq.size() > 0)
                {
                    val = dq.back();
                    if(grid[i][val] < grid[i][j])
                        dq.pop_back();
                    else break;
                }
                dq.push_back(j);
            }

            for(int j = k; j <= n; j++)
            {
                while(dq.size() > 0)
                {
                    val = dq.back();
                    if(grid[i][val] < grid[i][j])
                        dq.pop_back();
                    else break;
                }
                dq.push_back(j);

                memz[i][j] = grid[i][dq.front()];

                while(dq.size() > 0)
                {
                    val = dq.front();
                    if(val <= j - k + 1)
                        dq.pop_front();
                    else break;
                }
            }
        }


        for(int i = k; i <= n; i++)
        {
            deque<int> dq;
            for(int j = 1; j < k; j++)
            {
                while(dq.size() > 0)
                {
                    val = dq.back();
                    if(memz[val][i] < memz[j][i])
                        dq.pop_back();
                    else break;
                }
                dq.push_back(j);
            }
            for(int j = k; j <= n; j++)
            {
                while(dq.size() > 0)
                {
                    val = dq.back();
                    if(memz[val][i] < memz[j][i])
                        dq.pop_back();
                    else break;
                }
                dq.push_back(j);
                ans = ans + memz[dq.front()][i];
                while(dq.size())
                {
                    val = dq.front();
                    if(val <= j - k + 1)
                        dq.pop_front();
                    else break;
                }
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
    return 0;
}
