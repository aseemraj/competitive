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
    int n, x, y, c;
    cin>>n;
    while(n--)
    {
        c = 0;
        cin>>x>>y;
        while(x!=y)
        {
            if(x>y)
                x = x>>1;
            else
                y = y>>1;
            c++;
        }
        cout<<c<<endl;
    }
    return 0;
}
