/*
Author: aseemraj
Problem: 100712d
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

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        int dp[1005] = {0};
        rloop(i, 0, n)
        {
            dp[i] = INT_MAX;
            bool alter = true;
            for(int j = i; j - i + 1 <= k && j < n; j++)
            {
                if(j>i && s[j]==s[j-1]) alter = false;
                if(i==j || (!alter))
                    dp[i] = min(dp[i], 1 + dp[j+1]);
            }
        }
        cout<<dp[0] - 1<<"\n";
    }    
    return 0;
}
