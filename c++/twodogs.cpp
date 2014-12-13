#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int present[1000005];
int t[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, ans, i;
    memset(present, -1, sizeof present);
    t[0] = -1;
    cin>>n>>k;
    ans = n<<1;
    for(i=1;i<=n/2;i++)
    {
        cin>>t[i];
        if(present[t[i]]!=-1)
        {
            if(present[t[i]]>i && t[i]!=t[present[k-t[i]]])
                present[t[i]] = i;
        }
        else
            present[t[i]] = i;
    }
    for(i=n/2+1;i<=n;i++)
    {
        cin>>t[i];
        if(present[t[i]]!=-1)
        {
            if(present[t[i]]<=n/2 && present[t[i]]>n-i+1 && t[i]!=t[present[k-t[i]]])
                present[t[i]] = i;
            else if(present[t[i]]<=n && present[t[i]]>n/2 && n-present[t[i]]+1>n-i+1 && t[i]!=t[present[k-t[i]]])
                present[t[i]] = i;
        }
        else
            present[t[i]] = i;
    }
    for(i=1;i<=n/2;i++)
    {
        if(present[k-t[i]]>0 && present[k-t[i]]<=n/2 && t[i]!=t[present[k-t[i]]])
            ans = min(ans, max(i, present[k-t[i]]));
        else if(present[k-t[i]]>n/2 && present[k-t[i]]<=n && t[i]!=t[present[k-t[i]]])
            ans = min(ans, max(i, n+1-present[k-t[i]]));
    }
    for(i=n/2+1;i<=n;i++)
    {
        if(present[k-t[i]]>0 && present[k-t[i]]<=n/2 && t[i]!=t[present[k-t[i]]-1])
            ans = min(ans, max(n-i+1, present[k-t[i]]));
        else if(present[k-t[i]]>n/2 && present[k-t[i]]<=n && t[i]!=t[present[k-t[i]]])
            ans = min(ans, max(n-i+1, n+1-present[k-t[i]]));
        i++;
    }
    if(ans==2*n)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
