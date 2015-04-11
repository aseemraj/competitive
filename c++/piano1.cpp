/*
Author: aseemraj
Problem: PIANO1
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
    ll t, n, len, c = 0;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s>>n;
        n = 12*n;
        c = 1;
        len = s.length();
        loop(i, 0, len)
        {
            if(s[i]=='T')c+=2;
            else c+=1;
        }
        ll k = n/(c-1);
        cout<< k*n - (c-1)*k*(k+1)/2 <<"\n";
    } 
    return 0;
}
