#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, t;
    cin>>n;
    vector<int> p, m, e;
    loop(i, 1, n+1)
    {
        cin>>t;
        if(t==1)p.push_back(i);
        else if(t==2)m.push_back(i);
        else e.push_back(i);
    }
    int w = min(p.size(), min(m.size(), e.size()));
    cout<<w<<endl;
    loop(i, 0, w)
        cout<<p[i]<<' '<<m[i]<<' '<<e[i]<<endl;
    return 0;
}
