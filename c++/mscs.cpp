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
    int n, i, j;
    int m;
    cin>>n;
    int elem[n];
    int s[n];
    for(i=0;i<n;i++)
        cin>>elem[i];
    s[0] = elem[0];
    m = s[0];
    for(i=1;i<n;i++)
    {
        s[i] = max(s[i-1]+elem[i], elem[i]);
        if(s[i]>m)
            m = s[i];
    }
    cout<<m<<endl;
    return 0;
}
