#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <limits>
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

int main()
{
    int t, n, p;
    string s1, s2;
    bool same[n][n][n];
    while(t--)
    {
        cin>>n>>p;
        char cube1[n][n][n];
        char cube2[n][n][n];
        memset(same, false, sizeof(same));
        cin>>s1>>s2;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    cube1[i][j][k] = s1[i*n*n + j*n + k];
                    cube2[i][j][k] = s2[i*n*n + j*n + k];
                    if(cube1[i][j][k] == cube2[i][j][k])
                        same[i][j][k] = true;
                }
            }
        }
    }
    return 0;
}
