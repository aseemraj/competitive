#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int t, n, c, ans, k;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n;
        loop(i, 1, n+1)
        {
            c = 0;
            k = i;
            while(k>0)
            {
                k = k&(k-1);
                c++;
            }
            ans += c;
        }
        cout<<ans<<endl;
    }
    return 0;
}
