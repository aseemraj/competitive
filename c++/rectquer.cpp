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
#define ll long long
using namespace std;
int n;
int a[302][302][11];
int mark[302][11];
int q;
int main()
{
    memset(a, 0, sizeof(a));
    int i, j, k, cnt, temp;
    int x1, x2, y1, y2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>temp;
            a[i][j][0] = temp;
            for(k=1;k<11;k++)
            {
                a[i][j][k] = a[i][j-1][k];
            }
            a[i][j][temp] = 1+a[i][j-1][temp];
        }
    }
    cin>>q;
    while(q--)
    {
        cnt = 0;
        memset(mark, 0, sizeof(mark));
        cin>>x1>>y1>>x2>>y2;
        for(j=x1;j<=x2;j++)
        {
            for(i=1;i<11;i++)
            {
                mark[j][i] = a[j][y2][i] - a[j][y1-1][i] + mark[j-1][i];
            }
        }
        for(i=1;i<11;i++)
        {
            if(mark[x2][i]!=0)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
