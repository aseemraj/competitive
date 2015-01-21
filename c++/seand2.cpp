#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    ll t, n, m, x, g, idx, mn, j;
    string a, s;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>m;
        ll b[m];
        ll rem[10] = {0}, cnt[10] = {0};
        loop(i, 0, m)
        {
            cin>>b[i];
            loop(k, 0, 10)
                rem[k]+=rem[k]%b[i];
        }
        n = a.length();
        loop(i, 0, n)cnt[a[i]-48]++;
        g = 0, mn = 0, j = 0;
        s = "";
        while(g<n)
        {
            idx = 0;
            mn = j*10 + 10;
            loop(i, 0, 10)
            {
                if(cnt[i]>0 && ((j*10) + rem[i]) < mn)
            }
        }
    }
    return 0;
}
