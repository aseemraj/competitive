#include<bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define ll long long
using namespace std;

int main()
{
    int i, m, c;
    string s, ans;
    cin>>s;
    while(s!="#")
    {
        ans="";
        c = 0;
        m = s.size();
        for(i=0;i<m-1;i++)
        {
            ans += s[i];
            if(s[i]=='1')
                c++;
        }
        if((s[m-1]=='e' && c%2==0) || (s[m-1]=='o' && c%2==1))
            cout<<ans<<0<<endl;
        else if((s[m-1]=='e' && c%2==1) || (s[m-1]=='o' && c%2==0))
            cout<<ans<<1<<endl;
        cin>>s;
    }
    return 0;
}
