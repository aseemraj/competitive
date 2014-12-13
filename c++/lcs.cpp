#include <iostream>
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
#define ll long long
using namespace std;
int m, n;
int lcs[1001][1001];
int main()
{
    string s1, s2;
    int i, j;
    cin>>s1>>s2;
    while(s1!="done")
    {
        m = s1.size();
        n = s2.size();
        for(i=0;i<m;i++)
            lcs[i][0] = 0;
        for(i=0;i<n;i++)
            lcs[0][i] = 0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                else
                    lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
        cout<<lcs[m][n]<<endl;
        cin>>s1>>s2;
    }
    return 0;
}

