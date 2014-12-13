#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
bool edge[1002][1002];
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, x, y;
    cin>>n>>m;
    int v[n+1];
    pair<int, int> cost[n+1];
    loop(i, 0, n)
        cost[i+1] = make_pair(0, i+1);
    loop(i, 1, n+1)
        cin>>v[i];
    loop(i, 0, m)
    {
        cin>>x>>y;
        edge[x][y] = true;
        edge[y][x] = true;
    }
    loop(i, 1, n+1)
    {
        loop(j, 1, n+1)
        {
            if(edge[i][j])
                cost[i].first += v[j];
        }
    }
    int ans = 0;
    sort(cost+1, cost+n+1);
    loop(i, 1, n+1)
    {
        ans += cost[i].first;
        cout<<ans<<' ';
        loop(j, 1, n+1)
        {
            if(edge[cost[i].second][j])
            {
                edge[cost[i].second][j] = false;
                edge[j][cost[i].second] = false;
                cost[index].first -= v[cost[i].second];
            }
        }
        sort(cost+i+1, cost+n+1);
    }
    cout<<ans<<endl;
    return 0;
}
