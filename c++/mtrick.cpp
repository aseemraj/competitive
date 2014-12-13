#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll unsigned long long int
#define MAXN 1000000000000000000
using namespace std;
ll L[1001];
ll n, a, b, c;
string s="";

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a%c;
    while(b>0)
    {
        if(b&1)
            x = (x+y)%c;
        y = (y<<1)%c;
        b = b>>1;
    }
    return x%c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll i, j, m, k, mul, sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        loop(i, 0, n)
            cin>>L[i];
        cin>>a>>b>>c;
        cin>>s;
        mul = 1;
        sum = 0;
        loop(i, 0, n)
        {
            if(s[i]=='M')
            {
                mul = mulmod(mul, b, c);
                sum = mulmod(sum, b, c);
                L[i] = (mulmod(L[i], mul, c) + sum) % c;
            }
            else if(s[i]=='A')
            {
                sum = (sum + a) % c;
                L[i] = (mulmod(L[i], mul, c) + sum) % c;
            }
            else if(s[i]=='R')
            {
                L[n-1] = (mulmod(L[n-1], mul, c) + sum) % c;
                reverse(L+i, L+n);
            }
        }
        cout<<L[0];
        loop(i, 1, n)
            cout<<' '<<L[i];
        cout<<endl;
    }
    return 0;
}
