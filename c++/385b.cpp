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
    cin>>s;
    int n = s.size();
    int ans = 0;
    int fb = 0, lr = 0;
    loop(i, 0, n-3)
    {
        if(s[i]=='b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r')
        {
            ans += (i+1-fb)*(n-i-3);
            fb = i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
