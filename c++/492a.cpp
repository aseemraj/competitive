#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int f[100000], s[100000], n, j = 0;
    f[0] = 0;
    s[0] = 0;
    loop(i, 1, 100000)
    {
        s[i] = s[i-1] + i;
        f[i] = f[i-1] + s[i];
    }
    cin>>n;
    while(f[j]<=n)j++;j--;
    cout<<j<<endl;
    return 0;
}
