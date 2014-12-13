#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    int n, k, c;
    ll l, r, ans, t;
    cin>>n;
    while(n--)
    {
        cin>>l>>r;
        if(l==r){cout<<l<<endl;continue;}
        c = 0;
        t = l;
        while(t!=0){t>>=1;c+=1;}
        ans = l;
        while(ans<=r)
        {
            if((ans|(1LL<<k))>r)break;
            ans = ans|(1LL<<k);
            k++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
