#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, q, a, b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll d[n], s[n];
        loop(i, 0, n)
        {
            cin>>d[i];
            if(i==0)s[i]=d[i];
            else s[i]=s[i-1]+d[i];
        }
        cin>>q;
        while(q--)
        {
            cin>>a>>b;
            cout<<s[b]-s[a]<<endl;
        }
    }
    return 0;
}
