/*
Author: aseemraj
Problem: 516A
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
    int n;
    string s;
    cin>>n;
    cin>>s;
    string f="";
    loop(i, 0, n)
    {
        if(s[i]=='4')
            f += "322";
        else if(s[i]=='6')
            f += "53";
        else if(s[i]=='8')
            f += "7222";
        else if(s[i]=='9')
            f += "7332";
        else if(s[i]>'1')
            f += s[i];
    }
    sort(f.rbegin(), f.rend());
    cout<<f<<"\n";

    return 0;
}
