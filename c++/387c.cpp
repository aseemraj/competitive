#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int nz(string s)
{
    int n=s.size();
    int c=0;
    loop(i, 0, n)
        if(s[i]!='0')
            c++;
    return c;
}
int main()
{
    string s;
    int ans;
    cin>>s;
    int take_front;
    int n = s.size();
    int tz = 0;
    int i = n-1;
    while(s[i]=='0')
        i--;
    take_front = n - i;
    int nonz = nz(s);
    if(take_front*2>n)
        ans = 1;
    else if(take_front*2==n)
    {
        if(s[0]>=s[n-i])
            ans = 2;
        else
            ans = 1;
    }
    else
    {
        ans = nonz - nz(s.substr(0, take_front)) + 1;
    }
    cout<<ans<<endl;
    return 0;
}
