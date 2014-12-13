#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int n, c;
    cin>>n>>c;
    int x[n];
    loop(i, 0, n)
        cin>>x[i];
    int mx = 0;
    loop(i, 0, n-1)
    {
        if(x[i]-x[i+1]>mx)
            mx = x[i]-x[i+1];
    }
    if(mx-c>0)
        cout<<mx-c<<endl;
    else
        cout<<0<<endl;
    return 0;
}
