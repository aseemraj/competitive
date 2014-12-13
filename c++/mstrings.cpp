#include <iostream>
#include <string.h>
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
#define ll long long
using namespace std;

int main()
{
    string s;
    int t, i, m;
    cin>>t;
    while(t--)
    {
        cin>>s;
        m = s.size();
        for(i=0;i<=m/2;i++)
        {
            if(s[i]!=s[m-i-1])
                break;
        }
        i--;
        if(i==m/2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
