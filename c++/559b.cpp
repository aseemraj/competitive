/*
Author: aseemraj
Problem: 559b
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
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

string reduce(string a)
{
    if(a.length()%2==1)return a;
    string s = a.substr(0, a.length()/2);
    string t = a.substr(a.length()/2, a.length()/2);
    s = reduce(s);
    t = reduce(t);
    if(s<t)return s+t;
    else return t+s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    string a, b;
    cin>>a>>b;
    if(reduce(a)==reduce(b))
        cout<<"YES\n";
    else cout<<"NO\n";
    
    return 0;
}
