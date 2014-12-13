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
    int n, k;
    cin>>n>>k;
    while(n!=2013)
    {
        stringstream s;
        s<<n;
        cout<<"~n: "<<~n<<endl;
        cout<<"bits set: "<<__builtin_popcount(n)<<endl;
        cout<<"Lowest set bit: "<< (n & ~(n-1)) <<endl;
        cin>>n>>k;
    }
    return 0;
}

