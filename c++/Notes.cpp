#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
#define init(a, b) memset(a, b, sizeof(a))
#define all(c) c.begin(),c.end()
using namespace std;
int get(string pat, string txt)     //KMP
{
    int counter=0;
    int M = pat.length();
    int N = txt.length();
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (txt[i+j] != pat[j])
                break;
        }
        if (j == M)
        {
           counter++;
        }
    }
    return counter;
}
ll gcd(ll a, ll b)       //GCD
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
unsigned ll fac(unsigned ll n)
{
    return lround(exp(lgamma(n+1)));
}
int main()
{
    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b)<<' '<<fac(a)<<' '<<fac(b)<<endl;
    return 0;
}
