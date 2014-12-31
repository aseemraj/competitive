#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, t;
    cin>>n>>t;
    int a[n], to[n];
    loop(i, 1, n)
    {
        cin>>a[i];
        to[i] = i + a[i];
    }
    int x = 1;
    while(x<n && x!=t)
        x = to[x];
    if(x==t)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
