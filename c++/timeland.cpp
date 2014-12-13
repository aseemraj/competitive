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
    int t, n, k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int m=0;
        int a[n];
        loop(i, 0, n)
        {
            cin>>a[i];
            m = min(m, a[i]);
        }
        loop(i, 0, n)
        {
            m = a[i];
            for(int j=i;j<i+k+2&&j<n;j++)
            {
                if(a[i]>m)
            }
        }
    }
    return 0;
}
