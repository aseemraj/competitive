#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ll n, x, solved = 0;
    cin>>n>>x;
    ll a[n+1];
    loopl(i, 0, n)
        cin>>a[i];
    sort(a, a+n);
    ll f = n, s = 0;
    loopl(i, 0, n)
    {
        if(solved + a[i]%2==0?a[i]/2:a[i]/2+1 > x)
            break;
        solved += a[i]%2==0?a[i]/2:a[i]/2+1;
        f--;
    }
    if(f==0 && solved<x)
    {
        loopl(i, 0, n)
        {
            if(solved + a[i]/2 > x)
                break;
            solved += a[i]/2;
            s++;
        }
    }
    cout<<f<<' '<<s<<endl;
    return 0;
}
