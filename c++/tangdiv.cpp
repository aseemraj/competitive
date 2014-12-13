#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t, n, k, p, x, y;
    bool ans;
    cin>>t;
    while(t--)
    {
        map<int, bool> wanteds;
        map<int, bool> wantede;
        ans = true;
        cin>>n>>k>>p;
        loop(i, 0, k)
        {
            cin>>x>>y;
            wanteds[x] = true;
            wantede[y] = true;
        }
        loop(i, 0, p)
        {
            cin>>x>>y;
            if(!(wanteds[x] & wantede[y]))
                ans = false;
        }
        if(ans)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
