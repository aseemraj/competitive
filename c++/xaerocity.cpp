#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
typedef long long ll;
using namespace std;

bool lit[500005];
vector<int> adj[500005];
bool visited[500005];

int compute(int v, int p, bool plit)
{
    vector<int>::iterator it;
    int sum1 = 0, sum2 = 1;
    visited[v] = 1;
    if(lit[v])
    {
        for (it = adj[v].begin(); it != adj[v].end(); it++)
            if(*it != p)
                sum1 += compute(*it, v, 1);
        return sum1;
    }
    else
    {
        if(plit == 1)
        {
            for (it = adj[v].begin(); it != adj[v].end(); it++)
            {
                if(*it != p)
                {
                    sum1 += compute(*it, v, 0);
                    sum2 += compute(*it, v, 1);
                }
            }
            return min(sum1, sum2);
        }
        else
        {
            for (it = adj[v].begin(); it != adj[v].end(); it++)
                if(*it != p)
                    sum2 += compute(*it, v, 1);
            return sum2;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, u, v;
    cin>>t;
    while(t--)
    {
        memset(visited, 0, sizeof visited);
        cin>>n;
        for (int i = 1; i <= n; i++)
        {
            cin>>lit[i];
            adj[i].clear();
        }
        
        for (int i = 1; i < n; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<compute(1, 0, 1)<<"\n";

    }
    return 0;
}