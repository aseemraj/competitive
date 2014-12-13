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
    int t, n, i, j;
    cout<<"Test cases: ";
    cin>>t;
    while(t--)
    {
        cout<<"Number of numbers: ";
        cin>>n;
        int a[n], s[n];
        cout<<"All numbers: ";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s[i]=1;
        }
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(a[j]<=a[i] and s[j]+1>s[i])
                    s[i] = s[j] + 1;
            }
        }
        cout<<*max_element(s, s+n)<<endl;
    }
    return 0;
}
