/*
Author: aseemraj
Problem: frndmtng
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

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    double t1, t2, T1, T2, num, den;
    while(t--)
    {
        num = 0;
        cin>>T1>>T2>>t1>>t2;
        t1 = min(t1, T2);
        t2 = min(t2, T1);
        if(T1>=T2)
        {
            num = T1*T2 - (T2-t1)*(T2-t1)/2;
            if(T2+t2 >= T1)
                num -= (T1-t2)*(T1-t2)/2;
            else
                num -= T2*(T1-T2-t2) + T2*T2;
        }
        else
        {
            num = T1*T2 - (T1-t2)*(T1-t2)/2;
            if(T1+t1 >= T2)
                num -= (T2-t1)*(T2-t1)/2;
            else
                num -= T1*(T2-T1-t1) + T1*T1;
        }
        den = T1*T2;
        cout<<fixed<<setprecision(8)<<(num/den)<<"\n";
    }
    return 0;
}
