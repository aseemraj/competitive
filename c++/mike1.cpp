#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ll n, m, l, e1, e2;
    cin>>n>>m;
    ll a[n][m];
    loop(i, 0, n)
        loop(j, 0, m)
            cin>>a[i][j];
    cin>>l;
    pair <ll, ll> pr[l];
    loop(i, 0, l)
        cin>>pr[i].first>>pr[i].second;
    e1 = e2 = 0;
    loop(i, 0, l)
    {
        if(pr[i].first>n || pr[i].second>m)
        {
            e1 = -1;
            break;
        }
        e1 += a[pr[i].first-1][pr[i].second-1];
    }
    loop(i, 0, l)
    {
        if(pr[i].second>n || pr[i].first>m)
        {
            e2 = -1;
            break;
        }
        e2 += a[pr[i].second-1][pr[i].first-1];
    }
    cout<<max(e1, e2)<<endl;
    return 0;
}
