#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int a, b, burnt, rem = 0;
    cin>>a>>b;
    burnt = a;
    int ans = 0;
    while(ans<a)
    {
        ans++;
        if(ans%b==0)
            a++;
    }
    cout<<ans<<endl;
    return 0;
}
