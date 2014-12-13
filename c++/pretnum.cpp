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
    long long cur, multiple, l, r, i, j, MAX=1000001;
    int ans, x;
    bool prime[MAX];
    for(i=0; i<MAX; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for(i=2; i*i<MAX; i++)
        if(prime[i])
            for(j=i; j*i<MAX; j++)
                prime[i*j]=false;
    vector <long long> p;
    for(i=0; i<MAX; i++)
        if(prime[i])
            p.push_back(i);
    int siz = p.size();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        ans=0;
        for(i=0; i<siz; i++)
        {
            cur=p[i], mul=cur;
            x=1;
            while(cur<=r)
            {
                cur*=mul; x++;
                if(l<=cur && cur<=r && prime[x+1])
                    ans++;
            }
        }
    }
    return 0;
}
