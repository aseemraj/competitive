/*
Author: aseemraj
Problem: BITMAP
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
VP adj[200][200];
int nearest[200][200];
bool color[200][200];
bool visited[200][200];
int n, m;

int dfs(PI p)
{
    int x, y, dist = 40000;
    x = p.F, y = p.S;
    if(color[x][y]==1)
    {
        nearest[x][y] = 0;
        return 0;
    }
    if(nearest[x][y]!=-1)
    {
        return nearest[x][y];
    }

    for(VP::const_iterator i=adj[x][y].begin(); i!= adj[x][y].end(); i++)
    {
        PI pn = *i;
        if(nearest[pn.F][pn.S]==-1)
            dist = min(dist, 1 + dfs(pn));
    }
    nearest[x][y] = dist;
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    string row;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        loop(i, 0, n)
        {
            cin>>row;
            loop(j, 0, m)
            {
                nearest[i][j] = -1;
                visited[i][j] = 0;
                color[i][j] = row[j]-48;
                if(j>0)adj[i][j].PB(PI(i, j-1)), adj[i][j-1].PB(PI(i, j));
                if(i>0)adj[i][j].PB(PI(i-1, j)), adj[i-1][j].PB(PI(i, j));
            }
        }

        loop(i, 0, n)
        {
            loop(j, 0, m)
            {
                if(nearest[i][j]==-1)
                {
                    dfs(PI(i, j));
                }
            }
        }
        loop(i, 0, n)
        {
            loop(j, 0, m)
                cout<<nearest[i][j]<<' ';
            cout<<"\n";
        }
    }

    return 0;
}
