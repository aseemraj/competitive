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
    int n, i, c=0;
    cin>>n;
    while(n!=0)
    {
        c++;
        int a[n], sum=0, moves=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
        }
        int each = sum/n;
        for(i=0;i<n;i++)
        {
            if(a[i]<each)
                moves += each-a[i];
        }
        cout<<"\nSet #"<<c<<endl;
        cout<<"The minimum number of moves is "<<moves<<"."<<endl;
        cin>>n;
    }
    return 0;
}
