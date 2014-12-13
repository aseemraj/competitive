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

int main()
{
    int t, n, m, k, i, j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        string state[n];
        int rowo[n];
        memset(rowo, 0, sizeof(rowo));
        for(i=0;i<n;i++)
        {
            cin>>state[i];
            for(j=0;j<m;j++)
            {
                if(state[i][j]=='*')
                    rowo[i]++;
            }
        }

    }
    return 0;
}
