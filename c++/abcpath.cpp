/*
Author: aseemraj
Problem: abcpath
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
typedef long long ll;
using namespace std;

bool visited[55][55];
string grid[55];
int val[55][55];
int h, w;

int bfs(int r, int c)
{
    val[r][c] = 1;
    visited[r][c] = 1;
    loop(i, -1, 2)
    {
        loop(j, -1, 2)
        {
            if(r+i >= h || r+i < 0 || c+j >= w || c+j < 0 || grid[r+i][c+j] != grid[r][c] + 1)
                continue;
            if(visited[r+i][c+j])
                val[r][c] = max(val[r][c], val[r+i][c+j] + 1);
            else
                val[r][c] = max(val[r][c], bfs(r+i, c+j) + 1);
        }
    }
    return val[r][c];
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t = 0;
    while(1)
    {
        t++;
        memset(val, 0, sizeof val);
        memset(visited, 0, sizeof visited);
        cin>>h>>w;
        if(h==0)break;
        loop(i, 0, h)
            cin>>grid[i];
        loop(i, 0, h)
            loop(j, 0, w)
                if(!visited[i][j])
                    bfs(i, j);
        int mx = 0;
        loop(i, 0, h)
            loop(j, 0, w)
                if(grid[i][j] == 'A')
                    mx = max(mx, val[i][j]);
        cout<<"Case "<<t<<": "<<mx<<"\n";
    }
    return 0;
}
