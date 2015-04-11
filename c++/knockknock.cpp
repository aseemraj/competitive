/*
Author: Aseem Raj Baranwal
Problem: Knock Knock Codeagon
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
typedef unsigned long long ll;
using namespace std;
const ll MOD = 1000000000;
ll modulo(ll a,ll b)
{
    if(a==0 && b==0)return 0;
    ll x=1,y=a;
    while(b>0)
    {
        if(b&1)x=(x*y)%MOD;
        y = (y*y)%MOD;
        b = b/2;
    }
    return x%MOD;
}
ll gcd(ll a, ll b){if(a==0)return b;if(b==0)return a;ll c=a%b;while(c){a=b;b=c;c=a%b;}return b;}
ll rfunc(ll n)
{
    if(n<3)return 1;
    else if(n<5)return 3;
    else if(n<7)return 15;
    else if(n<=10)return 105;
    else
    {
        ll ans = (modulo(2, ceil(n/4.0)) * rfunc(ceil(n/5.0)))%MOD; 
        ans = (ans* rfunc(ceil(n/10.0)))%MOD;
        return ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t; ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll r = rfunc(n);
        if(r==0){cout<<0<<endl;continue;}
        ll mx = 0;
        for(ll i = 0; i <= 5*r; i +=r)
        {
            for(ll j = 0; j <= 5*r; j += r)
            {
                if(gcd(i/r, j/r)!=1)continue;
                n = modulo(i, j);
                if(n>mx)mx=n;
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
