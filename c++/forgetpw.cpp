#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string s, pass;
    map<char, char> ch;
    int t, n, st, en;
    char c, p;
    bool decimal;
    cin>>t;
    while(t--)
    {
        loop(i, 33, 127)
            ch[i] = ' ';
        cin>>n;
        loop(i, 0, n)
        {
            cin>>c>>p;
            ch[c] = p;
        }
        cin>>s;
        int sz = s.size();
        decimal = false;
        pass = "";
        loop(i, 0, sz)
        {
            if(ch[s[i]]!=' ') pass += ch[s[i]];
            else pass += s[i];
            if(pass[i]=='.') decimal = true;
        }
        st = 0;
        while(pass[st]=='0') st++;
        en = sz-1;
        if(decimal) while(pass[en]=='0') en--;
        if(pass[en]=='.') en--;
        if(st>en) cout<<0;
        else loop(i, st, en+1) cout<<pass[i];
        cout<<endl;
    }
    return 0;
}
