#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int cha[256];
    int chb[256];
    int t, n, m, ans;
    string a, b;
    cin>>t;
    while(t--)
    {
        ans = 0;
        memset(cha, 0, sizeof cha);
        memset(chb, 0, sizeof chb);
        cin>>a>>b;
        n = a.size();
        m = b.size();
        loop(i, 0, n)
            cha[int(a[i])]++;
        loop(i, 0, m)
            chb[int(b[i])]++;
        loop(i, 0, 256)
            ans += min(cha[i], chb[i]);
        cout<<ans<<endl;
    }
    return 0;
}
