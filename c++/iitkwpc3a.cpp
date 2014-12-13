#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll unsigned long long int
using namespace std;
int main()
{
    int t, i, j, n;
    string s, f;
    bool ans;
    char c;
    cin>>t;
    while(t--)
    {
        ans = true;
        f = "";
        cin>>s;
        n = s.size();
        c = s[0];
        f += s[0];
        loop(i, 1, n)
        {
            if(s[i]!=c)
            {
                c = s[i];
                f += c;
            }
        }
        n = f.size();
        loop(i, 0, n/2)
        {
            if(f[i]!=f[n-i-1])
            {
                ans = false;
                break;
            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
