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
    int n, m=0;
    cin>>n;
    int a[n];
    loop(i, 0, n)
        cin>>a[i];
    sort(a, a+n, greater<int>());
    loop(i, 0, n)
    {
        if(i+2+a[i]>m)
            m = i+2+a[i];
    }
    cout<<m<<endl;
    return 0;
}
