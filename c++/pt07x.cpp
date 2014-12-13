#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#define all(c) c.begin(), c.end()
#define ll long long
using namespace std;

vector <int> adj[100002];
ll dp[100002][2];
bool visited[100002];

ll cover(ll u, int withu)
{
    visited[u]=true;
    ll sum = 0;
    if(dp[u][withu]!=-1)
        return dp[u][withu];
    if(withu)
    {
        for(vector<int>::const_iterator i=adj[u].begin();i<adj[u].end();i++)
        {
            if(!visited[*i])
            {
                ll a = cover(*i, 0);
                ll b = cover(*i, 1);
                sum += min(a, b);
            }
        }
        dp[u][withu] = 1 + sum;
    }
    else
    {
        for(vector<int>::const_iterator i=adj[u].begin();i<adj[u].end();i++)
        {
            if(!visited[*i])
            {
                sum += cover(*i, 1);
            }
        }
        dp[u][withu] = sum;
    }
    visited[u]=false;
    return dp[u][withu];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));
    int n, i, u, v;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll a = cover(1, 0);
    ll b = cover(1, 1);
    cout<<min(a, b)<<endl;
    return 0;
}
