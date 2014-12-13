int lcs(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int dp[2][1000] = {{0}};
    int id;
    loop(i, 1, n+1)
    {
        id = i&1;           // Saving space as we need previous array only, not all
        loop(j, 1, m+1)
        {
            if(s1[i-1]==s2[j-1])dp[id][j] = dp[id^1][j-1]+1;
            else dp[id][j] = max(dp[id][j-1], dp[id^1][j]);
        }
    }
    return dp[id][m];
}
