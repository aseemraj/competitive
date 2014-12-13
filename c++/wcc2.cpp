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
    int t, al, ar, bl, br;
    cin>>t;
    while(t--)
    {
        cin>>al>>ar>>bl>>br;
        if((br>=al-1 && br<=2*al+2) || (bl>=ar-1 && bl<=2*ar+2))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
