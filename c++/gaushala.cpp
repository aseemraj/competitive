// number of ways to arrange three types of objects, a, b, anc c in quantity
// in such a way that no two adjacent elements in an arrangement are the same type
#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int dp[20][20][20][3];  // 3 for the three type of objects
int solve(int a, int b, int c, int last)
{
    if(a<0||b<0||c<0)return 0;
    if(last==0)
        return dp[a][b][c][0] = solve(a, b-1, c, 1) + solve(a, b, c-1, 2);
    else if(last==1)
        dp[a][b][c][1] = solve(a-1, b, c, 0) + solve(a, b, c-1, 2);
    else if(last==2)
        dp[a][b][c][2] = solve(a, b-1, c, 1) + solve(a-1, b, c-1, 0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, a, b, c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        loop(i, 0, a)loop(j, 0, b)dp[i][j][0][2] = 0;
        loop(i, 0, a)loop(j, 0, c)dp[i][0][j][1] = 0;
        loop(i, 0, b)loop(j, 0, c)dp[0][i][j][0] = 0;
        dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 1;
        loop(i, 1, a)
        {
            loop(j, 1, b)
            {
                loop(k, 1, c)
                {
                    dp[i][j][k][0] = dp[i][j-1][k][1] + dp[i][j][k-1][2];
                    dp[i][j][k][1] = dp[i-1][j][k][0] + dp[i][j][k-1][2];
                    dp[i][j][k][2] = dp[i-1][j][k][0] + dp[i][j-1][k][1];
                }
            }
        }
        cout<<dp[a][b][c][0]+dp[a][b][c][1]+dp[a][b][c][2]<<endl;
    }
    return 0;
}
