#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int a[1002][102];
int main()
{
    int n, m, k, x;
    cin>>n>>m>>k;
    cout<<m*(m-1)/2<<endl;
    loop(i, 0, m)
    {
        loop(j, i+1, m)
        {
            if(!k)
                cout<<i+1<<' '<<j+1<<endl;
            else
                cout<<j+1<<' '<<i+1<<endl;
        }
    }
    return 0;
}
