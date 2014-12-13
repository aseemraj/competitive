#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {if(b==0)return a; ll c=a%b; while(c!=0){a=b;b=c;c=a%b;} return b;}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t, oa, ob, ea, eb, n, m, num, den, gcf;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ea = n>>1;
        eb = m>>1;
        oa = n-ea;
        ob = m-eb;
        num = oa*eb + ea*ob;
        den = n*m;
        gcf = gcd(num, den);
        cout<<num/gcf<<'/'<<den/gcf<<endl;
    }
    return 0;
}
