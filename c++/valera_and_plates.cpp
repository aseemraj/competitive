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
    int n, b, p, cnt=0;
    cin>>n>>b>>p;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==2)
        {
            if(p==0)
            {
                if(b==0)
                    cnt++;
                else
                    b--;
            }
            else
                p--;
        }
        else
        {
            if(b==0)
                cnt+=1;
            else
                b--;
        }
    }
    cout<<cnt;

    return 0;
}
