/*
Author: aseemraj
Problem: sez
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

int n, m;
VI adj[205];
int visited[205];
int mark[205];
VI component[205];

void dfs(int v, int comp)
{
    visited[v] = 1, component[comp].PB(v);
    for(VI::iterator i = adj[v].begin(); i != adj[v].end(); i++)
        if(!visited[*i])
            dfs(*i, comp);
}

int maxval(int iter)
{
    int sz = component[iter].size();
    int value = 0, tempval = 0;
    loop(i, 0, sz)
    {
        loop(j, 0, 205)
            mark[j] = 0;

        int a = component[iter][i];
        mark[a] = 1, tempval = 1;
 
        for(VI::iterator j = adj[a].begin(); j != adj[a].end(); j++)
            mark[*j] = -1, tempval--;
 
        value = max(value, tempval);
        loop(j, 0, min(sz, 40))
        {
            if(mark[component[iter][j]])
                continue;
 
            int c = component[iter][j];
            loop(k, 1, n+1)
                visited[k] = mark[k];
            visited[c] = 1;
 
            for(VI::iterator k = adj[c].begin(); k != adj[c].end(); k++)
                visited[*k] = -1;
 
            tempval = 0;
            loop(k, 0, sz)
                tempval += visited[component[iter][k]];
 
            value = max(value, tempval);
            int cntunmarked, vfinal, mn;
 
            loop(p, 0, sz)
            {
                mn = 300;
                loop(x, 0, sz)
                {
                    if(!visited[component[iter][x]])
                    {
                        cntunmarked = 0;
                        int child = component[iter][x];
                        for(VI::iterator k = adj[child].begin(); k != adj[child].end(); k++)
                            if(visited[*k] == 0)
                                cntunmarked++;
     
                        if(cntunmarked < mn)
                            mn = cntunmarked, vfinal = x;
                    }
                }
 
                if(mn==300)break;
 
                visited[component[iter][vfinal]] = 1;
                int ccur = component[iter][vfinal];
                
                for(VI::iterator k = adj[ccur].begin(); k != adj[ccur].end(); k++)
                    visited[*k] = -1;
 
                tempval = 0;
                loop(k, 0, sz)
                    tempval += visited[component[iter][k]];
                value = max(value, tempval);
            }
        }
    }
    return value;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    int u, v, sz, szv, a, b;
    while(m--)
    {
        cin>>u>>v;
        adj[u].PB(v), adj[v].PB(u);
    }

    int comp = 1;
    loop(i, 1, n+1)
        if(!visited[i])
            dfs(i, comp++);

    int sum = 0;
    loop(i, 1, comp+1)
        sum += maxval(i);
    cout<<sum<<"\n";
    return 0;
}