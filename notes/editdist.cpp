int edist(string s1, string s2)     // Classic Edit Distance Problem
{
    int n = s1.size(), m = s2.size();
    int addcost = 1, delcost = 1, repcost = 1;
    // if addcost != delcost, s1 -> s2 won't be same as s2 -> s1
    // Here we calculate cost of transforming s1 -> s2
    loop(i, 0, n+1)dp[i][0]=i*delcost;
    loop(j, 0, m+1)dp[0][j]=j*addcost;
    loop(i, 1, n+1)
    {
        loop(j, 1, m+1)
        {
            if(s1[i-1]==s2[j-1])dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1]+addcost, dp[i-1][j]+delcost));
            else dp[i][j] = min(dp[i-1][j-1]+repcost, min(dp[i][j-1]+addcost, dp[i-1][j]+delcost));
        }
    }
    return dp[n][m];
}
