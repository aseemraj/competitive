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
    int t, n, d;
    ll mn1, mn2;
    cin>>t;
    while(t--)
    {
        cost = 0;
        cin>>n>>d;
        int p[n];
        loop(i, 0, n)
            cin>>p[i];
        cost += p[0] + p[n-1];
        mn1 = min(p[1], p[2]);
        mn2 = max(p[1], p[2]);
        loop(i, 1, d+1)
        {
            if(p[i]<mn1)
            {
                mn2 = mn1;
                mn1 = p[i];
            }
            p[i] = p[0] + p[i];
        }
        loop(i, d+1, n)
        {
            mn = p[i-1];
            rloop(j, i-d, i)
            {
                mn = min(p[j], mn);
            }
            p[i] += mn;
        }
        cout<<p[n-1]<<endl;
    }
    return 0;
}
