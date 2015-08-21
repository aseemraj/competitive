/*
Author: aseemraj
Problem: gohan and blocks
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

map<string , int> stringMap;
string s;
ll ans1, ans2;

void CountAll(string s1, string s2, int idx)
{
    if(s2.size() == s.size())
    {
        if(stringMap[s2] == 0)
        {
            stringMap[s2] = 1;
            ans2++;
        }
    }
    if(s2 == s)
    {
        ans1++;
        return;
    }
    if(s1.size() != 0)
        CountAll(s1.substr(0, s1.size()-1), s2 + s1[s1.size()-1], idx);
    if(idx < s.size())
        CountAll(s1 + s[idx], s2, idx + 1);
}

int main()
{
    cin>>s;
    CountAll("", "", 0);
    cout<<ans1<<' '<<ans2<<"\n";
    return 0;
}