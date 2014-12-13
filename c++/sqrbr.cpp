#include <iostream>
#include<string.h>
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
int dp[40][40];
int mark[40], n, k;

int compute(int pos, int cnt)
{
    int &ans = dp[pos][cnt];
    if(cnt<0)
        return 0;
    if(ans!=-1)
        return ans;
    if(pos==n)
    {
        if(cnt==0)
            return 1;
        else
            return 0;
    }
    if(mark[pos]==1)
        ans = compute(pos+1, cnt+1);
    else
        ans = compute(pos+1, cnt+1) + compute(pos+1, cnt-1);
    return ans;
}

int main()
{
    int d, i, t;
    cin>>d;
    while(d--)
    {
        memset(dp, -1, sizeof(dp));
        memset(mark, 0, sizeof(mark));
        cin>>n>>k;
        n = 2*n;
        for(i=0;i<k;i++)
        {
            cin>>t;
            mark[t-1] = 1;
        }
        cout<<compute(0, 0)<<endl;
    }
    return 0;
}
