/*
Author: Aseem Raj Baranwal
Problem: Codeforces 508
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;
bool grid[1005][1005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k, ans=0, x, y;
    cin>>n>>m>>k;
    loop(i, 0, k)
    {
        cin>>x>>y;
        grid[x][y] = true;
        if(ans==0)
        {
            if(grid[x+1][y])
            {
                if(grid[x][y-1] && grid[x+1][y-1])
                    ans = i+1;
                else if(grid[x][y+1] && grid[x+1][y+1])
                    ans = i+1;
            }
            if(grid[x-1][y])
            {
                if(grid[x][y-1] && grid[x-1][y-1])
                    ans = i+1;
                else if(grid[x][y+1] && grid[x-1][y+1])
                    ans = i+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
