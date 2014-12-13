#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int t, n, a, index;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pair <int, int> p[n];
        int s[n], x[n], d[n];
        loop(i, 0, n)
        {
            cin>>s[i]>>x[i]>>d[i]>>a;
            p[i] = make_pair(a, i);
        }
        sort(p, p+n, greater< pair<int, int> >());
        loop(i, 0, n)
        {
            index = p[i].second;
        }
    }
    return 0;
}
