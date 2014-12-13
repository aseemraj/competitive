#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ll n, k, m, i, temp;
    int t, c;
    cin>>t;
    while(t--)
    {
        c = 0;
        cin>>n>>k>>m;
        i = n;
        while(i<=m && i>0)
        {
            c++;
            temp = i;
            i *= k;
            if(i<=temp)
                break;
        }
        c--;
        if(c<0)
            cout<<0<<endl;
        else
            cout<<c<<endl;
    }
    return 0;
}
