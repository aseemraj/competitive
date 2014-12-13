#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int dp[100001][10] = {{0}};
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, s, temp, x;
    cin>>n>>m;
    string digit;
    cin>>digit;
    loop(i, 1, n+1)
    {
        loop(j, 0, 10)
            dp[i][j] = dp[i-1][j];
        dp[i][int(digit[i-1])-48]++;
    }
    while(m--)
    {
        s = 0;
        cin>>x;
        x--;
        loop(i, 0, 10)
        {
            temp = int(digit[x])-48;
            s += abs(i-temp)*dp[x][i];
        }
        cout<<s<<endl;
    }
    return 0;
}
