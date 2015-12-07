/*
Author: aseemraj
Problem: cmpsstr
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
int lcs[100][100];
int lcsubstr(string a, string b)
{
    int m = a.length();
    int n = b.length();
    int mx = 0;
    loop(i, 0, m)
    {
        lcs[i][0] = 0;
        loop(j, 0, n)
        {
            lcs[0][j] = 0;
            if(a[i] == b[j])
                lcs[i+1][j+1] = lcs[i][j] + 1;
            else
                lcs[i+1][j+1] = 0;
            mx = max(mx, lcs[i+1][j+1]);
        }
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    string a, b;
    while(getline(cin, a))
    {
        getline(cin, b);
        cout<<lcsubstr(a, b)<<"\n";
    }
    return 0;
}
