#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
//vector<int> graph[1005];
int n;
bool g[1005][1005];
void dfs(int u, bool* visited)
{
    visited[u] = true;
    cout<<u<<' ';
    loop(i, 1, n+1)
        if(g[u][i] && !visited[i])
            dfs(i, visited);
}
void bfs(int u, bool* visited)
{
    list<int> q;
    visited[u] = true;
    q.push_back(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop_front();
        cout<<u<<' ';
        loop(i, 1, n+1)
        {
            if(g[u][i] && !visited[i])
            {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tt, m, x, y;
    cin>>tt;
    loop(t, 1, tt+1)
    {
        cin>>n;
        memset(g, 0, sizeof g);
        loop(i, 1, n+1)
        {
            cin>>x>>m;
            while(m--)
            {
                cin>>x;
                g[i][x] = true;
                g[x][i] = true;
            }
        }
        cin>>x>>y;
        cout<<"graph "<<t<<endl;
        while(x!=0 || y!=0)
        {
            bool visited[1005] = {0};
            if(y==0)dfs(x, visited);
            else bfs(x, visited);
            cout<<endl;
            cin>>x>>y;
        }
    }
    return 0;
}
