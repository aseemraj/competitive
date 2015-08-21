/*
Author: aseemraj
Problem: minus
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

int dp[105][20005];
int a[105], n, m;

void printorder(string ans)
{
    int k = 0, i = 0;
    while(i<n-1)
    {
        k++;
        if(ans[i]=='-'){i++;continue;}
        while(i<n-1 && ans[i]=='+')
        {
            cout<<k<<"\n";
            i++;
        }
        k--;
    }
    for(i=1; i<=k; i++)
        cout<<1<<"\n";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, offset = 10000;
    string ans;
    cin>>t;

    while(t--)
    {

        loop(i, 0, 105)
            loop(j, 0, 20005)
                dp[i][j] = 0;

        cin>>n>>m;

        loop(i, 0, n)cin>>a[i];

        dp[0][a[0]+offset] = 1;
        if(n>1)dp[1][a[0]-a[1]+offset] = -1;

        loop(i, 2, n)
        {
            loop(j, 0, 20002)
            {
                if(dp[i-1][j] != 0)
                {
                    dp[i][j + a[i]] = 1;
                    dp[i][j - a[i]] = -1;
                }
            }
        }

        int k = m + offset;
        ans = "";
        rloop(i, 1, n)
        {
            if(dp[i][k] == 1)
            {
                ans = "+" + ans;
                k -= a[i];
            }
            else if(dp[i][k] == -1)
            {
                ans = "-" + ans;
                k += a[i];
            }
        }
        
        printorder(ans);
    }

    return 0;
}
