#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    ll n, r, avg, a, b, sum=0, k;
    cin>>n>>r>>avg;
    vector<pair<ll, ll> > v;
    loop(i, 0, n)
    {
        cin>>a>>b;
        v.push_back(make_pair(b, a));
        sum+=a;
    }
    sum = avg*n - sum;  // required additional grade points
    ll c = 0;
    sort(v.begin(), v.end());
    loop(i, 0, n)
    {
        if(sum<=0)break;
        if(v[i].second<r)
        {
            k = min(sum, r-v[i].second);    // number of essays to write for this exam
            sum -= k;
            c += k*v[i].first;
        }
    }
    cout<<c<<endl;
    return 0;
}
