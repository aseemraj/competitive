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
#define MAX 150001
int index(char c)
{
    if(c>=65 && c<=90)
        return c-65;
    return c-97;
}
int main()
{
    int t, m, i;
    char c;
    string f1, f2;
    string s;
    cin>>t;
    while(t--)
    {
        vector < pair <int, int> > freq;
        map <char,int> ioc;
        for(i=0;i<26;i++)
            freq.push_back(make_pair(0, i));
        f2="";
        cin>>f1;
        getline(cin, s);
        getline(cin, s);
        m = s.size();
        for(i=0;i<m;i++)
        {
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
                freq[index(s[i])].first++;
        }
        sort(freq.begin(), freq.end());
        for(i=0;i<26;i++)
        {
            ioc[char(freq[i].second+97)] = i;
        }
        for(i=0;i<m;i++)
        {
            if(s[i]<65 || s[i]>122 || (s[i]>90 && s[i]<97))
                f2 += s[i];
            else
            {
                if(s[i]>=97)
                    f2 += f1[ioc[s[i]]];
                else
                {
                    f2 += char(f1[ioc[char(index(s[i])+97)]] - 32);
                }
            }
        }
        cout<<f2<<endl;
    }
    return 0;
}
