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
    freopen("output1.txt", "w", stdout);
    int n, t = 1;
    while(getline(cin, s))
    {
        n = s.length();
//        printf("%s\n", s);
        int cnt1 = 0, cnt2 = 0;
        int x = 0;
        for (int i = 0; i < n; i++)
        {
			if (x == 0 && s[i] == '1' || x == 1 && s[i] == '0') cnt1++, x ^= 1;
		}


        int i = 0;
        while(i<n && s[i] == '0')i++;
        if(i == n)
        {
            cnt2 = -1;
        }
        i++;
        while(i<n)
        {
            if(s[i] != s[i-1])
                cnt2++;
            i++;
        }
        if(cnt1 != (cnt2 + 1))
        {
            cout<<"yes\n";
        }
        else
            cout<<"no\n";
    }
    return 0;
}
