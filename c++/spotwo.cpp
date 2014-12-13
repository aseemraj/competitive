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

unsigned long long bin(int n)
{
    int i;
    unsigned long long result=0, adder;
    for (i = 1 << 20; i > 0; i = i / 2)
    {
        adder = (n & i)?1:0;
        result = result*10 + adder;
    }
    return result;
}
long long int modular_pow(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long x = 1, y = a, temp;
    int i;
    while(b>0)
    {
        if(b%10==1)
            x = (x*y)%c;
        temp = y;
        for(i=1;i<10;i++)
        {
            y = (y*temp)%c;
        }
        b /= 10;
    }
    return x%c;
}
int main()
{
    int t;
    unsigned long long n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<modular_pow(4, bin(n), 1000000007)<<endl;
    }
    return 0;
}
