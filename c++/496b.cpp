#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
char upd(char x, int k){return char(((x-48+k)%10)+48);}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n;
    string s, mn="";
    cin>>s;
    loop(i, 0, n)mn+='9';
    loop(add, 0, 10)
    {
        loop(i, 0, n)
        {
            s[i] = char(s[i]+1);
            if(s[i]>'9')s[i]='0';
        }
        loop(shift, 0, n)
        {
            string x = s.substr(shift, n-shift) + s.substr(0, shift);
            loop(i, 0, n)
            {
                if(x[i]<mn[i])mn=x;
                else if(x[i]>mn[i])break;
            }
        }
    }
    cout<<mn<<endl;
    return 0;
}
