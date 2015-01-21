#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, x, n, k, c, d;
    ll mx, sum;
    bool f;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==0)
        {
            if((n*(n+1)/2)&1)cout<<"Mom\n";
            else cout<<"Chef\n";
            continue;
        }
        ll a[k+1];
        mx = a[0] = sum = 0;
        loop(i, 1, k+1){cin>>a[i];sum+=a[i];}
        sort(a, a+k+1);
        f = 0;
        loop(i, 1, k+1)
        {
            mx += a[i]*(a[i]-1)/2 - a[i-1]*(a[i-1]+1)/2;
            if(mx<a[i]){f=1;break;}
        }
        if(f)
        {
            if(mx&1)cout<<"Mom\n";
            else cout<<"Chef\n";
        }
        else
        {
            if(((n*(n+1)/2)-sum)&1)cout<<"Mom\n";
            else cout<<"Chef\n";
        }
    }
    return 0;
}
