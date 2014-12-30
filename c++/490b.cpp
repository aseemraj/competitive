#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int p[1000005];
int f[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, a, b, j, c;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        p[a] = b;
        f[a]++;
        f[b]--;
    }
    j = 0;
    while(f[j]!=1)j++;
    c = p[0];
    while(c && j)
    {
        cout<<j<<' '<<c<<' ';
        j = p[j];
        c = p[c];
    }
    if(j)cout<<j;
    return 0;
}
