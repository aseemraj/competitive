#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int sum, lim, n, ans;
    vector<pair<int, int> > v;
    vector<int> av;
    cin>>sum>>lim;
    n = sum;
    loop(i, 1, lim+1)
        v.push_back(make_pair(i&-i, i));
    sort(v.rbegin(), v.rend());
    ans = 0;
    bool flag = false;
    loop(i, 0, v.size())
    {
        if(v[i].first<=n)
        {
            ans++;
            n -= v[i].first;
            av.push_back(v[i].second);
        }
        if(n==0)
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        cout<<ans<<endl;
        cout<<av[0];
        loop(i, 1, av.size())
            cout<<' '<<av[i];
        cout<<endl;
    }
    else
        cout<<"-1\n";
    return 0;
}
