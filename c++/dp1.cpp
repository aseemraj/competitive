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
using namespace std;

int main()
{
    int sum, coins, i, j, t;
    cin>>t;
    while(t--)
    {
        cin>>coins>>sum;
        int coin[coins];
        for(i=0;i<coins;i++)
            cin>>coin[i];
        for(i=1;i<=sum;i++)
            ans[i] = coins*sum;

        int ans[sum+1];
        ans[0] = 0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<coins;j++)
            {
                if(i>=coin[j] && ans[i-coin[j]+1 < ans[i])
                    ans[i] = ans[i-coin[j]]+1;
            }
        }
        cout<<a[i]<<endl;
    }
    return 0;
}
