#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int n = s.size();
    int c[n+1], k, fin;
    c[0] = 0;
    loop(i, 0, n)
    {
        if(s[i]=='(')c[i+1] = c[i]+1;
        else if(s[i]==')')c[i+1] = c[i]-1;
        else if(s[i]=='#')c[i+1] = c[i]-1, k = i;
        if(c[i+1]<0){cout<<"-1\n";return 0;}
    }
    fin = c[n];
    loop(i, k, n){c[i+1]-=c[n];if(c[i+1]<0){cout<<"-1\n";return 0;}}
    loop(i, 0, n)
    {
        if(s[i]=='#')
        {
            if(i<k)cout<<1<<endl;
            else cout<<fin+1<<endl;
        }
    }
    return 0;
}
