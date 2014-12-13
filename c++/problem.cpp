#include <iostream>
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
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
int main()
{
    int t, m, n, i, j, c;
    cin>>t;
    while(t--)
    {
        cin>>m;
        int s[m];
        for(i=0;i<m;i++)
        {
            cin>>s[i];
        }
        cin>>n;
        int f[n];
        for(i=0;i<n;i++)
        {
            cin>>f[i];
        }
        int a[m+1][n+1];
        for(i=0;i<=m;i++)
            a[i][0]=i;
        for(i=0;i<=n;i++)
            a[0][i]=i;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                int diff=1;
                if(s[i-1]==f[j-1])
                    diff=0;
                a[i][j] = min(a[i-1][j]+1, min(a[i][j-1]+1, a[i-1][j-1]+diff));
            }
        }
        cout<<a[m][n]<<endl;
    }
    return 0;
}
