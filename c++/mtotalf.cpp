#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int graph[200][200];
vector< pair<char, int> > adj[200];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, f;
    char x, y;
    cin>>n;
    while(n--)
    {
        cin>>x>>y>>f;
        graph[x][y] += f;
        graph[y][x] += f;
        adj[x].push_back(make_pair(y, f));
        adj[y].push_back(make_pair(x, f));
    }
    return 0;
}
