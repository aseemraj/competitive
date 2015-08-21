/*
Author: aseemraj
Problem: 100650h
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

int dp[1020][1020];
int num[1050];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n;
    m = n/2;
    int alpha = 1;
    while(n>0)
    {
        for(int i= 0;i < n;i++)
            cin>>num[i];
        for(int k = 0;k < n-1;k++)
        {
            dp[k][k+1] = abs(num[k] - num[k+1]);
        }

        int i,j,k;
        int first,second;
        for(k = 1;k < m;k++)
        {
            i = 0;
            for(j = 2*k+1;j < n;j++, i++)
            {
                //case first pick
                first = num[i];
                if(num[i+1] > num[j])
                {
                    first = first - num[i+1] + dp[i+2][j];
                }
                else if(num[i+1] < num[j])
                {
                    first = first - num[j] + dp[i+1][j-1];
                }
                else
                {
                    first = first - num[j] + max(dp[i+2][j],dp[i+1][j-1]);
                }

                //case last pick

                second = num[j];
                if(num[i] > num[j-1])
                {
                    second = second - num[i] + dp[i+1][j-1];
                }
                else if(num[i] < num[j-1])
                {
                    second = second - num[j-1] + dp[i][j-2];
                }
                else
                {
                    second = second - num[j-1] + max(dp[i+1][j-1],dp[i][j-2]);
                }
                dp[i][j] = max(first,second);
            }
        }

        
        cout << "In game " << alpha << ", the greedy strategy might lose by as many as " << dp[0][n-1] << " points."<< endl;
        cin>>n;
        m = n/2;
        alpha++;
    }
    
    return 0;
}
 