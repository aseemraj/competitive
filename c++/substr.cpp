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

int get(string pat, string txt)
{
    int counter=0;
    int m = pat.length();
    int n = txt.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (txt[i+j] != pat[j])
                break;
        if (j == m)
           counter++;
    }
    return counter;
}

int main()
{
    string x, k;
    int t;
    long kint, n, i;
    cin>>t;
    while(t--)
    {
        x="";
        cin>>n>>kint;
        for(i=1;i<=n;i++)
        {
            stringstream s1;
            s1 << i;
            x += s1.str();
        }
        stringstream s2;
        s2 << kint;
        string k = s2.str();
        cout<<get(k, x)<<endl;
    }
    return 0;
}
