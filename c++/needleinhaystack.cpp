#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    string pat, text, ext;
    int n, m, j, temp;
    bool ans = false;
    while(t--)
    {
        ans = false;
        cin>>pat>>text;
        ext = text;
        n = pat.size();
        sort(&pat[0], &pat[0]+n);
        string ch = "";
        loop(i, 0, n)
            ch += text[i];
        sort(&ch[0], &ch[0]+n);
//        cout<<ch<<endl;
        if(n>text.size())
            ans = false;
        else if(pat==ch)
            ans = true;
        else
        {
            m = text.size();
            j = 1;
            while(j<m-n+1)
            {
                ch = "";
                loop(i, j, j+n)
                    ch += text[i];
                sort(&ch[0], &ch[0]+n);
//                cout<<ch<<endl;
                if(ch==pat)
                {
                    ans = true;
                    break;
                }
                j++;
            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
