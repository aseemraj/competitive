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
unsigned long long A[100];
unsigned long long fib_rec(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    return fib_rec(n-1)+fib_rec(n-2);
}

unsigned long long fib(int n)
{
    if(n==0)
        return A[0];
    else if(n==1)
        return A[1];
    if(A[n]!=-1) return A[n];
    A[n] = fib(n-1)+fib(n-2);
    return A[n];
}

int main()
{
    A[0] = 0;
    A[1] = 1;
    for(int i=2;i<100;i++)
        A[i] = -1;
    cout<<fib(40)<<endl;
    return 0;
}

