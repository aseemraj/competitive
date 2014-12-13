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

int gcd(int a, int b)
{
    int c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    int t, x[2], y[2];
    cin>>t;
    while(t--)
    {
        cin>>x[0]>>y[0]>>x[1]>>y[1];
        if(x[0]==x[1] or y[0]==y[1])
            cout<<0<<endl;
        else
        {
            int dx = abs(x[0]-x[1]);
            int dy = abs(y[0]-y[1]);
            int sub = gcd(dx, dy);
            dx = dx/sub;
            dy = dy/sub;
            cout<<sub*(dx + dy - 1)<<endl;
        }
    }
    return 0;
}
