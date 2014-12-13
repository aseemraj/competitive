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
#define range(i, n) for(i=0;i<n;i++)
using namespace std;

int main()
{
    int n, i;
    cin>>n;
    while(n != 0)
    {
        int a[n];
        range(i, n)
        {
            cin>>a[i];
            cout<<a[i];
        }
        cin>>n;
    }
    return 0;
}
