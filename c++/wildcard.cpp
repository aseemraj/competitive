/*
Author: aseemraj
Problem: wildcard
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

bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    int i = 0, j = 0, lastStar = -1, lastConfirmed = 0;
    while(i < n)
    {
        if(j<m && (s[i] == p[j] || p[j] == '?'))
            i++, j++;
        else if(j<m && p[j] == '*')
        {
            lastStar = j;
            lastConfirmed = i;
            j++;
        }
        else if(lastStar != -1)
        {
            lastConfirmed++;
            i = lastConfirmed;
            j = lastStar + 1;
        }
        else return false;
    }
    while(j<m && p[j]=='*')j++;
    if(j!=m)return false;
    else return true;
}


bool isMatchDP(string s, string p)
{
    int n = s.length(), m = p.length();
    int i = 0, j = 0;
    bool dp[2][10000] = {{0}};
    dp[0][0] = 1;
    
    while(i<m && p[i] == '*')
    {
        dp[0][i+1] = 1;
        i++;
    }

    int x = 0;
    for(i = 1; i <= n; i++)
    {
        x = x^1;
        for(j = 1; j <= m; j++)
        {
            if(p[j-1] == '*')
                dp[x][j] = dp[x^1][j] || dp[x][j-1];
            else
                dp[x][j] = dp[x^1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
        }
        dp[x^1][0] = 0;
    }
    return dp[x][m];
}


int main()
{
    ios_base::sync_with_stdio(0);
    string s, p;
    while(1)
    {
        cin>>s>>p;
        cout<<isMatchDP(s, p)<<"\n";
    }
    return 0;
}