/*
Author: aseemraj
Problem: googleA
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<string, int> mp;
map<int, string> rmp;


bool cust_compare(pair<int, string> a, pair<int, string> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll cases, p, n, k, m;
    cin>>cases;
    for (int t = 1; t <= cases; t++)
    {
        k = 0;
        mp.clear();
        rmp.clear();
        cin>>p;
        ll s[105] = {0};
        for(int i = 0; i < p; i++)
            cin>>s[i];

        cin>>n;
        ll w[105] = {0};
        string name;
        vector< multiset <ll> > v;

        for(int i = 0; i < n; i++)
        {
            cin>>w[i];
            for(int j = 0; j < p; j++)
            {
                cin>>name;
                if(mp.find(name) == mp.end())
                {
                    rmp[k] = name;
                    mp[name] = k++;
                    multiset<ll> st;
                    st.insert(w[i]*s[j]);
                    v.push_back(st);
                }
                else
                    v[mp[name]].insert(w[i]*s[j]);
            }
        }

        cin>>m;

        vector< pair <ll, string> > ans(k);
        ll cnt, sum, rnk;
        for(int i = 0; i < k; i++)
        {
            cnt = sum = 0;
            for(multiset<ll>::reverse_iterator it = v[i].rbegin(); it != v[i].rend(); it++)
            {
                if(cnt == m)break;
                sum += (*it);
                cnt++;
            }
            ans[i] = (make_pair(sum, rmp[i]));
        }
        sort(ans.begin(), ans.end(), cust_compare);
        cout<<"Case #"<<t<<":\n";

        cnt = 0;
        rnk = 0;
        ll prev = -1;
        for(vector<pair< ll, string> >::iterator it = ans.begin(); it != ans.end(); it++)
        {
            rnk++;
            if(it->first != prev)
                cnt = rnk;
            cout<<cnt<<": "<<it->second<<"\n";
            prev = it->first;
        }
    }
    return 0;
}
