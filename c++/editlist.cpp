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
int a[2001][2001];
int main()
{
    int t, m, n, i, j, c;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        int m = s1.size();
        int n = s2.size();
        for(i=0;i<=m;i++)
            a[i][0]=i;
        for(i=0;i<=n;i++)
            a[0][i]=i;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                int diff=1;
                if(s1[i-1]==s2[j-1])
                    diff=0;
                a[i][j] = min(a[i-1][j]+1, min(a[i][j-1]+1, a[i-1][j-1]+diff));
            }
        }
        cout<<a[m][n]<<endl;
    }
    return 0;
}
