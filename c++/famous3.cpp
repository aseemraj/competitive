#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
#define MOD 1000000007
using namespace std;
void multiply(ll F[2][2], ll M[2][2])
{
    ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD;
    ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD;
    ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD;
    ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(ll F[2][2], ll n)
{
    if(n==0||n==1)return;
    ll M[2][2] = {{2,2},{1,0}};
    power(F, n/2);
    multiply(F, F);
    if(n%2 != 0)multiply(F, M);
}
ll fib(ll n)
{
    ll F[2][2] = {{2,2},{1,0}};
    if(n==1)return 1;
    if(n==2)return 2;
    power(F, n-1);
    return F[0][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    ll n, a=1, b=2, c=6;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0){cout<<0<<endl;continue;}
        n--;
        cout<<(3*(fib(3*n+1)+fib(3*n+2)))%MOD<<endl;
    }
    return 0;
}
