#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    ll c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

ll power(ll b, ll e, ll m)
{
    ll remainder;
    ll x = 1;
    while (e != 0)
    {
        remainder = e%2;
        e= e/2;
        if(remainder == 1)
            x = (x*b) % m;
        b = (b*b) % m;
    }
    return x;
}

int main()
{
    ll n, m, k, res=0;
    cin>>n>>k>>m;
    loopl(i, 1, n)
    {
        if(gcd(n, i)==1)
            res = (res + power(i, k, m))%m;
    }
    cout<<res<<endl;
    return 0;
}
