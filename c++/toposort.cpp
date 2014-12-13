#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
vector<int> adj[10005];
void toposort(int v, bool *visited, list<int> &s)
{
    visited[v] = true;
    for(vector<int>::iterator i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            toposort(*i, visited, s);
    s.push_back(v);
}
bool isCyclic(int v, bool *visited, bool *recstack)
{
    if(!visited[v])
    {
        visited[v] = true;
        recstack[v] = true;
        for(vector<int>::iterator i=adj[v].begin();i!=adj[v].end();i++)
        {
            if(!visited[*i]&&isCyclic(*i, visited, recstack))
                return true;
            else if(recstack[*i])
                return true;
        }
    }
    recstack[v] = false;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, x, y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    loop(i, 1, n+1)
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    bool visited1[10005] = {0};
    bool recstack[10005] = {0};
    bool ans = true;
    loop(i, 1, n+1)
        if(isCyclic(i, visited1, recstack))
        {ans = false;break;}
    if(!ans){cout<<"Sandro fails.\n";return 0;}
    bool visited[10005] = {0};
    list<int> s;
    for(int i=n; i>=1; i--)
        if(!visited[i])
            toposort(i, visited, s);
    while(!s.empty())
    {
        cout<<s.back()<<' ';
        s.pop_back();
    }
    cout<<endl;
    return 0;
}
