#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
bool checkbpm(int u, vector<int> *adj, int* mark, bool* visited)
{
    list<int> q;
    int newmark;
    visited[u] = true;
    q.push_back(u);
    mark[u] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop_front();
        if(mark[u]==1)newmark=2;
        else if(mark[u]==2)newmark=1;
        for(vector<int>::const_iterator i=adj[u].begin();i!=adj[u].end();i++)
        {
            if(mark[*i]==mark[u])return false;
            mark[*i] = newmark;
            if(!visited[*i])
            {
                q.push_back(*i);
                visited[*i] = true;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tt, n, m, x, y;
    cin>>tt;
    loop(t, 1, tt+1)
    {
        cout<<"Scenario #"<<t<<':'<<endl;
        cin>>n>>m;
        vector<int> adj[n+1];
        while(m--)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int mark[2005] = {0};   // 1 is female, 2 is male, 0 is in unknown.
        bool visited[2005] = {0};
        bool ans = true;
        loop(i, 1, n+1)
        {
            if(!visited[i])
                if(!checkbpm(i, adj, mark, visited))
                    {cout<<"Suspicious bugs found!\n";ans=false;break;}
        }
        if(ans)cout<<"No suspicious bugs found!\n";

    }
    return 0;
}
