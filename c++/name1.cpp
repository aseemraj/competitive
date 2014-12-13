#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, sz;
    bool ans;
    string a, b, s, c;
    cin>>t;
    while(t--)
    {
        ans = true;
        int cntc[26] = {0};
        int cntp[26] = {0};
        cin>>a>>b;
        c = "";
        cin>>n;
        loop(i, 0, n)
        {
            cin>>s;
            c += s;
        }
        sz = c.size();
        loop(i, 0, sz)
            cntc[c[i]-'a']++;
        s = a+b;
        sz = s.size();
        loop(i, 0, sz)
            cntp[s[i]-'a']++;
        loop(i, 0, 26)
            if(cntc[i]>cntp[i])
            {
                ans = false;
                break;
            }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
