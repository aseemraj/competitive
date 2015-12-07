/*
Author: aseemraj
Problem: 578a
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
    // ios_base::sync_with_stdio(0);
    int a, b, n;
    double x1, x2, x;
    scanf("%d %d",&a,&b);
    if(a < b)
        printf("-1\n");
    else
    {
        n = (a-b)/(2*b);
        if(a == b)
            x1 = a;
        if(n > 0)
            x1 = (double)(a-b)/(double)(2*n);
        else
            x1 = -1;
        n = (a+b)/(2*b);
        if(n > 0)
            x2 = (double)(a+b)/(double)(2*n);
        else
            x2 = -1;

        x = -1;
        if(x1 == -1)
            x = x2;
        else if(x2 != -1)
            x = min(x1,x2);
        if(x == -1)
            printf("-1\n");
        else
            printf("%.12lf\n",x);
    }
    return 0;
}
