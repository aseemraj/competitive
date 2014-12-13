#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
ll a[300002];
ll b[300002];
ll n, ans[555555];
ll q;
ll elem, index;
vector< pair <long, long> > v;
int main()
{
    cin>>n;
    loop(i, 0, n)
    {
        cin>>q;
        v.push_back(make_pair(q,i+1));
    }
    sort(v.begin(), v.end());
    elem = -1;
    loop(i, 0, v.size())
    {
        index = v[i].second;
        elem++;
        if(elem < v[i].first)
            elem = v[i].first;
        ans[index] = elem;
    }
    cout<<ans[1];
    loop(i, 1, n)
        cout<<" "<<ans[i+1];
    cout<<endl;
    return 0;
}
