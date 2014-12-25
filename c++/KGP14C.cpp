#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
bool adj[505][505];
int c[2];   // c[0] = number of people on table 1, c[1] on table 2
bool checkbpm(int u, int* mark, bool* visited, int n)
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
        loop(i, 1, n+1)
        {
            if(adj[u][i] && mark[i]==mark[u])return false;
            else if(adj[u][i])
            {
                mark[i] = newmark;
                if(!visited[i])
                {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tt, n, m, x;
    cin>>tt;
    loop(t, 1, tt+1)
    {
        cin>>n;
        loop(i, 0, n+1)loop(j, 0, n+1)adj[i][j]=0;
        loop(i, 1, n+1)
        {
            cin>>m;
            while(m--)
            {
                cin>>x;
                adj[x][i] = adj[i][x] = 1;
            }
        }
        cout<<"Case "<<t<<": ";
        int mark[505] = {0};   // 1 is on table 1, 2 is on table 2, 0 is unknown.
        bool visited[505] = {0};
        bool ans = true;
        c[0] = c[1] = 0;
        loop(i, 1, n+1)
        {
            if(!visited[i])
                if(!checkbpm(i, mark, visited, n))
                    {cout<<"0 0 0\n";ans=false;break;}
        }
        if(ans)
        {
            loop(i, 1, n+1)
            {
                if(mark[i]==1)c[0]++;
                else if(mark[i]==2)c[1]++;
            }
            cout<<1<<' '<<min(c[0],c[1])<<' '<<max(c[0],c[1])<<endl;
        }

    }
    return 0;
}
