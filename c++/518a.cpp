/*
Author: aseemraj
Problem: 518A
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
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    string s, t;
    cin>>s>>t;

    int sz = s.size();
    int j = sz-1;
    while(s[j]=='z' && j>=0)
    {
        s[j] = 'a';
        j--;
    }
    if(j<0)
        cout<<"No such string\n";
    else
    {
        s[j]++;
        if(s<t)cout<<s<<"\n";
        else cout<<"No such string\n";
    }

    return 0;
}