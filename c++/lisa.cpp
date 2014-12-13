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
    int t, i, l, j, k;
    string s;
    cin>>t;
    while(t--)
    {
        vector <int> nums;
        vector <char> oper;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(i%2 == 0)
                nums.push_back(atoi(&s[i]));
            else
                oper.push_back(s[i]);
        }
        vector < vector <ll> > mins(nums.size() + 1, vector<ll>(nums.size() + 1, numeric_limits<int>::max()));
        vector < vector <ll> > maxs(nums.size() + 1, vector<ll>(nums.size() + 1, 0));
        for(i=0;i<=nums.size();i++)
            maxs[i][i] = mins[i][i] = nums[i];
        int n = nums.size();
        for(l=2;l<=n;l++)
        {
            for(i=0;i<=n-l;i++)
            {
                j = i + l - 1;
                for(k=i;k<j;k++)
                {
                    int min_tmp = 0;
                    int max_tmp = 0;
                    if(oper[k] == '+')
                    {
                        min_tmp = mins[i][k] + mins[k+1][j];
                        max_tmp = maxs[i][k] + maxs[k+1][j];
                    }
                    else if(oper[k] == '*')
                    {
                        min_tmp = mins[i][k] * mins[k+1][j];
                        max_tmp = maxs[i][k] * maxs[k+1][j];
                    }
                    if(min_tmp < mins[i][j])
                        mins[i][j] = min_tmp;
                    if(max_tmp > maxs[i][j])
                        maxs[i][j] = max_tmp;
                }
          }
        }
        cout<<maxs[0][n-1]<<" "<<mins[0][n-1]<<endl;
    }
    return 0;
}
