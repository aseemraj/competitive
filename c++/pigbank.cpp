#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#define all(c) c.begin(), c.end()
using namespace std;

#define Max 10000

int dp[Max+1];
bool temp[Max+1];
int w[500],v[500];

int main()
{
    int t,e,f,n;
    int i,j;

    cin>>t;
    while(t--)
    {


        cin>>e>>f>>n;
        for(i=0;i<n;i++)
            cin>>v[i]>>w[i];

        memset(dp,0,sizeof(dp));
        memset(temp,false,sizeof(temp));
        temp[0]=true;
        for(i=0;i<n;i++)
        {
            for(j=w[i];j<=Max;j++)
            {
                if(temp[j-w[i]]&&dp[j]!=0)
                {
                     dp[j]=dp[j]<dp[j-w[i]]+v[i]? dp[j]:dp[j-w[i]]+v[i];
                     temp[j]=true;
                }
                else if(temp[j-w[i]]&&dp[j]==0)
               {
                    dp[j]=dp[j-w[i]]+v[i];
                    temp[j]=true;
                }
            }
        }
        if(temp[f-e]==false)
        {
            cout<<"This is impossible."<<endl;
        }
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<'.'<<endl;
    }
   return 0;
}
