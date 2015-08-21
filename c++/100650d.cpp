/*
Author: aseemraj
Problem: 100650D
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

bool invalid[1005][1005];

int board[1005][1005];
// 0 = empty
// 1 = pawn
// 2 = knight
// 3 = queen

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k, x, y, t, test = 1;
    cin>>n>>m;
    while(n>0 && m>0)
    {
        loop(i, 0, n+1)
            loop(j, 0, m+1)
                board[i][j] = 0, invalid[i][j] = 0;

        // queens
        cin>>k;
        loop(i, 0, k)
        {
            cin>>x>>y;
            board[x][y] = 3;
        }
        
        // knights
        cin>>k;
        loop(i, 0, k)
        {
            cin>>x>>y;
            board[x][y] = 2;
        }
        
        // pawns
        cin>>k;
        loop(i, 0, k)
        {
            cin>>x>>y;
            board[x][y] = 1;
        }
        
        loop(i, 1, n+1)
        {
            loop(j, 1, m+1)
            {
                if(invalid[i][j] && board[i][j]==0)continue;
                if(board[i][j] > 0)invalid[i][j] = 1;

                if(board[i][j] == 2)
                {
                    if(i+2 <= n && j+1 <= m)
                        invalid[i+2][j+1] = 1;
                    if(i+2 <= n && j-1 > 0)
                        invalid[i+2][j-1] = 1;
                    if(i-2 > 0 && j+1 <= m)
                        invalid[i-2][j+1] = 1;
                    if(i-2 > 0 && j-1 > 0)
                        invalid[i-2][j-1] = 1;

                    if(i+1 <= n && j+2 <= m)
                        invalid[i+1][j+2] = 1;
                    if(i+1 <= n && j-2 > 0)
                        invalid[i+1][j-2] = 1;
                    if(i-1 > 0 && j+2 <= m)
                        invalid[i-1][j+2] = 1;
                    if(i-1 > 0 && j-2 > 0)
                        invalid[i-1][j-2] = 1;
                }

                else if(board[i][j] == 3)
                {
                    t = i + 1;
                    while(t<=n && board[t][j]==0)
                        invalid[t][j] = 1, t++;
                    t = i-1;
                    while(t>0 && board[t][j]==0)
                        invalid[t][j] = 1, t--;
                    t = j+1;
                    while(t<=m && board[i][t]==0)
                        invalid[i][t] = 1, t++;
                    t = j-1;
                    while(t>0 && board[i][t]==0)
                        invalid[i][t] = 1, t--;
                    
                    t = 1;
                    while(i+t<=n && j+t<=m && board[i+t][j+t]==0)
                        invalid[i+t][j+t] = 1, t++;
                    t = 1;
                    while(i+t<=n && j-t>0 && board[i+t][j-t]==0)
                        invalid[i+t][j-t] = 1, t++;
                    t = 1;
                    while(i-t>0 && j+t<=m && board[i-t][j+t]==0)
                        invalid[i-t][j+t] = 1, t++;
                    t = 1;
                    while(i-t>0 && j-t>0 && board[i-t][j-t]==0)
                        invalid[i-t][j-t] = 1, t++;
                }
            }
        }

        int cnt = 0;
        loop(i, 1, n+1)
            loop(j, 1, m+1)
                if(!invalid[i][j])
                    cnt++;

        cout<<"Board "<<test<<" has "<<cnt<<" safe squares.\n";

        cin>>n>>m;
        test++;
    }
    
    return 0;
}
