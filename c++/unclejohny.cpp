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
    int n, t, i, k, temp, johny;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int d[n];
        for(i=0;i<n;i++)
            cin>>d[i];
        cin>>k;
        johny = d[k-1];
        sort(d, d + n);
        cout<<distance(d, find(d, d + n, johny))+1<<endl;
    }
    return 0;
}
