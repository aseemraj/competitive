#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    int n;
    ll x, y, mxx, mxy, mnx, mny;
    cin>>n;
    cin>>x>>y;
    mxx = x;
    mxy = y;
    mnx = x;
    mny = y;
    loop(i, 1, n)
    {
        cin>>x>>y;
        mxx = max(mxx, x);
        mxy = max(mxy, y);
        mnx = min(mnx, x);
        mny = min(mny, y);
    }
    ll side = max(mxx-mnx, mxy-mny);
    cout<<side*side<<endl;
    return 0;
}
