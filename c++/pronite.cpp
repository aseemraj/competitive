#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll ans = 1;
        while(m!=n)
        {
            ans++;
            if(m>n)m-=n;
            else n-=m;
        }
        cout<<ans<<endl;
    }
    return 0;
}
