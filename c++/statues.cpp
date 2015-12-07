/*
Author: aseemraj
Problem: statues
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

int main()
{
    ios_base::sync_with_stdio(0);
    int n, c = 0;
    cin>>n;
    while(n!=0)
    {
        c++;
        int a[n], sum=0, moves=0;
        loop(i, 0, n)
        {
            cin>>a[i];
            sum += a[i];
        }
        int each = sum/n;
        loop(i, 0, n)
        {
            if(a[i]<each)
                moves += each - a[i];
        }
        cout<<"Set #"<<c<<"\n";
        cout<<"The minimum number of moves is "<<moves<<"."<<"\n\n";
        cin>>n;
    }
    return 0;
}
