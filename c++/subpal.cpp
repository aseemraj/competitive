/*
Author: aseemraj
Problem: subpal
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
int cnt[200];
int n, odd;
string s;

int solve(int i, int j)
{
    if(odd < 2)
        return (j-i+1);
    if(cnt[s[i]] % 2 == 1)
    {
        i++;
        cnt[s[i]]--;
        odd--;
        return solve(i+1, j);
    }
    else if(cnt[s[j]] % 2 == 1)
    {
        j--;
        cnt[s[j]]--;
        odd--;
        return solve(i, j-1);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        memset(cnt, 0, sizeof cnt);
        odd = 0;
        cin>>s;
        n = s.length();
        loop(i, 0, n)
            cnt[s[i]]++;
        loop(i, 97, 123)
            odd += cnt[i]%2;
        solve(0, n-1);
    }
    return 0;
}
