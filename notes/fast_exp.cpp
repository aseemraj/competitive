#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;

int modulo(int a,int b,int c)
{
    ll x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b>0)
    {
        if(b%2 == 1)
            x=(x*y)%c;
        y = (y*y)%c; // squaring the base
        b = b>>1;
    }
    return x%c;
}
int main()
{
    return 0;
}
