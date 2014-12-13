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

long long int modular_pow(int a, long long int b, long long int c)
{
    long long int x = 1, y = a;
    while(b>0)
    {
        if(b%2==1)
            x = (x*y)%c;
        y = (y*y)%c;
        b /= 2;
    }
    return x%c;
}
int main()
{
    int t;
    long long int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<modular_pow(2, n, 1000000007) - 1<<endl;
    }
    return 0;
}
