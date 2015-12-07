/*
Author: aseemraj
Problem: pebble
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
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t = 1;
    while(getline(cin, s))
    {
        n = s.length();
//        printf("%s\n", s);
        int i = 0;
        int cnt = 0;
        while(i<n && s[i] == '0')i++;
        cout<<"Game #"<<t<<": ";
        if(i == n)
        {
            cout<<"0\n";
            continue;
        }
        i++;
        while(i<n)
        {
            if(s[i] != s[i-1])
                cnt++;
            i++;
        }
        cout<<cnt+1<<"\n";
        t++;
    }
    return 0;
}
