#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n, k, s, f, p, pref, sum, j, e;
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin>>n>>k;
        vector <pair <ll, pair <ll, ll> > > cust;
        loopl(i, 0, n)
        {
            cin>>s>>f>>p;
            cust.push_back(make_pair(p, make_pair(f, s)));
        }

//        sum++;
//        e = 0;
//        p = v[0].first;
//        loopl(d, 1, n)
//        {
//            if(v[d].first>p)
//            {
//                p = v[d].first;
//                e = d;
//                d++;
//                sum++;
//            }
//            if(d>=n)
//                break;
//            if(v[d].second.second>=v[e].second.first)
//            {
//                sum++;
//                e = d;
//            }
//        }        cout<<sum<<endl;
    }
    return 0;
}
