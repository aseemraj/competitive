#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
typedef long long ll;
using namespace std;
vector<int> adj[10005];
vector<int> cityforprod[105];
set<int> products;
bool visited[10005];
int ans[10005][105];
int product[10005];
void bfs(int v, int b, int k)
{
    memset(visited, 0, sizeof visited);
    visited[v] = visited[b] = 1;
    list<int> q;
    q.push_back(v);
    while(!q.empty())
    {
        v = q.front();
        visited[v] = 1;
        q.pop_front();
        for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
            {
                loop(j, 1, k+1)
                    if(ans[*i][j]==0 && ans[v][j]!=0)
                        ans[*i][j] = ans[v][j];
                q.push_back(*i);
            }
        }
    }
}
void dfs(int v, int k)
{
    ans[v][product[v]] = v;
    visited[v] = 1;
    for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!visited[*i])
        {
            dfs(*i, k);
            loop(j, 1, k+1)
            {
                if(ans[v][j]==0)
                    ans[v][j] = ans[*i][j];
                else if(ans[v][j]>ans[*i][j] && ans[*i][j]!=0)
                    ans[v][j] = ans[*i][j];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, b, a, p, q;
    cin>>n>>k>>b;
    loop(i, 0, n-1)
    {
        cin>>a>>p;
        adj[a].pb(p);
        adj[p].pb(a);
    }
    loop(i, 1, n+1)
    {
        cin>>p;
        cityforprod[p].pb(i);
        product[i] = p;
        products.insert(p);
    }
    loop(i, 1, k+1)sort(cityforprod[i].begin(), cityforprod[i].end());
    dfs(b, k);
    for(vector<int>::iterator i=adj[b].begin(); i!=adj[b].end(); i++)
        bfs(*i, b, k);
    loop(i, 1, n+1)
        loop(j, 1, k+1)
            if(ans[i][j]==0 && products.find(j)!=products.end())
                ans[i][j] = cityforprod[j][0];
    cin>>q;
    while(q--)
    {
        cin>>a>>p;
        if(products.find(p)!=products.end())cout<<ans[a][p]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
