#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pair<int, int> range[n];
        loop(i, 0, n)cin>>range[i].first>>range[i].second;
        sort(range, range+n);
        vector<pair<int,int> > v;
        v.push_back(range[0]);
        c = 0;
        loop(i, 1, n)
        {
            if(range[i].first>v[c].second)v.push_back(range[i]),c++;
            else v[c].second = min(v[c].second, range[i].second);
        }
        cout<<c+1<<endl;
    }
    return 0;
}
