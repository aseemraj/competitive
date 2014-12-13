#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
bool ispalin(string s)
{
    int n = s.size();
    loop(i, 0, n/2)if(s[i]!=s[n-i-1])return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, st, en;
    string s, f;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n = s.size();
        st = en = -1;
        loop(i, 0, n/2)
        {
            if(s[i]!=s[n-i-1])
            {
                st = i;
                en = n-i;
                break;
            }
        }
        f = "";
        if(st!=-1 && en!=-1)
        {
            loop(i, st, en)f+=s[i];
            n = f.size();
            bool ans = false;
            if(f[0]==f[n-2])ans=ispalin(f.substr(0,n-1));
            if(f[n-1]==f[1])ans=ans||ispalin(f.substr(1,n-1));
            if(ans)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;
}
