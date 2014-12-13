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

bool is_fine(long long int x)
{
    int rem;
    while(x>0)
    {
        rem = x%10;
        if(rem!=0 and rem!=1 and rem!=4 and rem!=9)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    vector <unsigned long long> perfects;
    int t;
    long long int a, b, i, mid, high, low, limitlow, limithigh;
    for(i=0;i<=100000;i++)
    {
        if(is_fine(i*i))
        {
            perfects.push_back(i*i);
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        low = 0;
        high = perfects.size();
        while(low<=high)
        {
            mid = (low+high)/2;
            if(perfects[mid]<a)
                low = mid + 1;
            else if(perfects[mid]>a)
                high = mid-1;
            else
                break;
        }
        if(perfects[mid]==a)
            limitlow = mid;
        else if((perfects[mid]<a and perfects[mid+1]>a) or perfects[mid+1]==a)
            limitlow = mid+1;
        else if(perfects[mid]>a and perfects[mid-1]<a)
            limitlow = mid;
        else if(perfects[mid-1]==a)
            limitlow = mid-1;
        low = 0;
        high = perfects.size();
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if(perfects[mid]<b)
                low = mid + 1;
            else if(perfects[mid]>b)
                high = mid-1;
            else
                break;
        }
        if(perfects[mid]==b)
            limithigh = mid;
        else if(perfects[mid]<b and perfects[mid+1]>b)
            limithigh = mid;
        else if((perfects[mid]>b and perfects[mid-1]<b) or perfects[mid-1]>=b)
            limithigh = mid-1;
        else if(perfects[mid+1]==b)
            limithigh = mid+1;
        cout<<limithigh - limitlow + 1<<endl;
    }
    return 0;
}
