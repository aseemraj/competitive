#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    ll k, mx;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll a[n], b[n];
        mx = 0;
        loop(i, 0, n)cin>>a[i];
        loop(i, 0, n)cin>>b[i];
        loop(i, 0, n)mx = max((k/a[i])*b[i], mx);
        cout<<mx<<endl;
    }
    return 0;
}
