/*
Author: aseemraj
Problem: ACODE
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
    string s;
    int sz;
    while(1)
    {
        cin>>s;
        if(s=="0")break;
        int dp[5005] = {0};
        dp[0] = 1;
        dp[1] = 1;
        sz = s.size();
        loop(i, 2, sz+1)
        {
            if(s[i-1]!='0')
                dp[i] = dp[i-1];
            if(s[i-2]>48 && 10*(s[i-2]-48) + s[i-1] - 48 <= 26)
                dp[i] += dp[i-2];
        }
        cout<<dp[sz]<<"\n";
    }
    

    return 0;
}
