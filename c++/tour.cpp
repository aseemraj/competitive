/*
Author: aseemraj
Problem: tour
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

VI adj[1005];
VI adjt[1005];
bool visited[1005];
int comp[1005];
int indegree[1005];

void dfs(int v, stack<int> &s)
{
    visited[v] = true;
    for(VI::iterator i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            dfs(*i, s);
    s.push(v);
}

void dfst(int v, int component)
{
    visited[v] = true;
    comp[v] = component;
    for(VI::iterator i=adjt[v].begin();i!=adjt[v].end();i++)
        if(!visited[*i])
            dfst(*i, component);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m, x, component;
    cin>>t;
    while(t--)
    {
        cin>>n;
        loop(i, 1, n+1)
        {
            adj[i].clear();
            adjt[i].clear();
        }
        loop(i, 1, n+1)
        {
            cin>>m;
            while(m--)
            {
                cin>>x;
                adj[x].push_back(i);
                adjt[i].push_back(x);
            }
        }
        memset(visited, 0, sizeof visited);
        memset(indegree, 0, sizeof indegree);
        stack<int> s;
        loop(i, 1, n+1)
            if(!visited[i])
                dfs(i, s);
        memset(visited, 0, sizeof visited);
        component = 0;
        while(!s.empty())
        {
            x = s.top();
            s.pop();
            if(!visited[x])
                dfst(x, component++);
        }
        loop(i, 1, n+1)
        {
            for(VI::iterator j=adj[i].begin();j!=adj[i].end();j++)
            {
                if(comp[i]!=comp[*j])
                    indegree[comp[*j]]++;
            }
        }
        int cnt = 0, ans = 1;
        loop(i, 0, component)
        {
            if(indegree[i]==0)
                cnt++;
            if(cnt>1)
            {
                ans = 0;
                break;
            }
        }
        if(ans)
        {
            cnt = 0;
            loop(i, 1, n+1)
            {
                if(indegree[comp[i]]==0)
                    cnt++;
            }
            cout<<cnt<<endl;
        }
        else cout<<"0\n";
    }
    return 0;
}
