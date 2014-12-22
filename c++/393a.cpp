#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    string s;
    int x=0, n=0, i=0, e=0, t=0;
    cin>>s;
    loop(j, 0, s.size())
    {
        if(s[j]=='n')
            n++;
        else if(s[j]=='i')
            i++;
        else if(s[j]=='e')
            e++;
        else if(s[j]=='t')
            t++;
    }
    while(n-2>=0 && i-1>=0 && e-3>=0 && t-1>=0)
    {
        x++;
        n -= 2;
        i--;
        t--;
        e -= 3;
    }
    x--;
    if(n>0)x++;
    if(x>0)cout<<x<<endl;
    else cout<<0<<endl;
    return 0;
}
