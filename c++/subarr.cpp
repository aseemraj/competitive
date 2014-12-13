#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
#define MAX 1000002
ll a[MAX];
ll sum[MAX];
using namespace std;
int main()
{
    ll n, k, c=0;
    cin>>n>>k;
    sum[0] = 0;
    loopl(i, 0, n)
    {
        cin>>a[i];
        sum[i+1] = sum[i] + a[i];
    }
    loopl(l, 1, n+1)
    {
        loopl(r, l, n+1)
        {
            if((sum[r] - sum[l-1])/(r-l+1)>=k)
                c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
