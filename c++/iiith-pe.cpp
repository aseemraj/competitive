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
    int t, n, m, i, j, t1, t2, cntf, cntb;
    cin>>t;
    while(t--)
    {
        cntf = 0;
        cntb = 0;
        cin>>n>>m;
        if(m==0)
            cout<<n<<endl;
        else
        {
            map <int, pair <int, int> > imp;
            for(i=1;i<=n;i++)
            {
                imp[i].first = -1;
                imp[i].second = -1;
            }
            for(i=0;i<m;i++)
            {
                cin>>t1>>t2;
                if(imp[t1].second==-1)
                {
                    if(t1+1==t2)
                    {
                        imp[t1].second = t2;
                        cntf++;
                    }
                    else if(t1==n && t2==1)
                    {
                        imp[n].second = 1;
                        cntf++;
                    }
                }
                if(imp[t1].first==-1)
                {
                    if(t1-1==t2)
                    {
                        imp[t1].first = t2;
                        cntb++;
                    }
                    else if(t1==1 && t2==n)
                    {
                        imp[1].first = n;
                        cntb++;
                    }
                }
            }
            if(cntf==n || cntb==n)
                cout<<0<<endl;
            else if(cntf==n-1 && cntb==n-1)
            {
                i=1;
                while(imp[i].second!=-1)
                    i = imp[i].second;
                if(imp[i].first!=-1)
                    cout<<0<<endl;
                else
                    cout<<1<<endl;
            }
            else
                cout<<n-max(cntf, cntb)<<endl;
        }
    }
    return 0;
}
