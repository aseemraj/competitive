/*
Author: aseemraj
Problem: 100685g
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
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

#define SUBLIME
#if defined SUBLIME
#  define ISTREAM ifile
#else
#  define ISTREAM cin
#endif

typedef long long ll;
using namespace std;

set<int> path[100005];
bool visited[100005];

void dfs(int u)
{
    visited[u] = 1;
    for(set<int>::iterator it = path[u].begin(); it != path[u].end(); it++)
    {
        if(!visited[*it])
            dfs(*it);
    }
    for(set<int>::iterator it = path[u].begin(); it != path[u].end(); it++)
        path[u].insert(path[*it].begin(), path[*it].end());
}

int main()
{
    // ios_base::sync_with_stdio(0);
    #if defined (SUBLIME)
      std::ifstream ifile("test.input");
    #endif
    
    int n, m, a, b;
    scanf("%d", &n);

    loop(i, 1, n)
    {
        scanf("%d %d", &a, &b);
        path[a].insert(b);
    }

    loop(i, 1, n+1)
        if(!visited[i])
            dfs(i);



    cin>>m;
    
    while(m--)
    {
        scanf("%d %d", &a, &b);
        if(path[a].find(b) != path[a].end() || a == b)printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
