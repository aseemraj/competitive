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
using namespace std;

int main()
{
    int t, n, i, j, sum;
    cout<<"Number of test cases: ";
    cin>>t;
    while(t--)
    {
        cout<<"Number of coins: ";
        cin>>n;
        int v[n];
        cout<<"Values of coins: ";
        for(i=0;i<n;i++)
        {
            cin>>v[i];
        }
        cout<<"Sum for which minimum number is to be found: ";
        cin>>sum;
        int ans[sum+1];
        ans[0]=0;
        for(i=1;i<=sum;i++)
            ans[i]=sum+1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=sum;j++)
            {
                if(ans[j]+1<ans[v[i]+j])
                {
                    ans[v[i]+j] = ans[j] + 1;
                }
            }
        }
        cout<<"\nSum\tMin coins\n";
        for(i=0;i<=sum;i++)
        {
            if(ans[i]!=sum+1)
            {
                cout<<i<<"\t"<<ans[i];
            }
            else
                cout<<i<<"\tImpossible";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
