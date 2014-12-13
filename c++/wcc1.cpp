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
    int t, n, k, a, b, c, d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=n+1;
        while(k<9013)
        {
            a = k%10;
            b = (k/10)%10;
            c = (k/100)%10;
            d = (k/1000)%10;
            if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
            {
                cout<<k<<endl;
                break;
            }
            k++;
        }
    }
    return 0;
}
