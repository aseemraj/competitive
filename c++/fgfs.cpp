#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    long k, s, f, p, a, b;
    int n, sum, i;
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin>>n>>k;
        vector <pair <ll, pair <ll, ll> > > v;
        loop(i, 0, n)
        {
            cin>>s>>f>>p;
            v.push_back(make_pair(p, make_pair(s, f)));
        }
        sort(v.begin(), v.end());
        loop(i, 0, n)
        {
            p = v[i].first;
            s = v[i].second.first;
            f = v[i].second.second;
            sum++;
            while(v[i].first==p && i<n)
            {
                a = v[i].second.first;
                b = v[i].second.second;
                if(!((a>=s&&a<f)||(b>=s&&b<f)))
                {
                    sum++;
                    s = a;
                    f = b;
                }
                else if(a>=s&&a<f&&b>=s&&b<f)
                {
                    s = a;
                    f = b;
                }
                i++;
            }
            i-=1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
