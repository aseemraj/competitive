cout<<"0 | ";loop(j, 0, m+1)cout<<j<<' ';
cout<<endl;loop(j, 0, m+1)cout<<"---";
cout<<endl;
loop(i, 0, n+1)
{
    cout<<i<<" | ";
    loop(j, 0, m+1)cout<<dp[i][j]<<' ';
    cout<<endl;
}
