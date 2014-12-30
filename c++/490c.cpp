#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
ll arem[1000002];
ll brem[1000002];
int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    ll a, b, pow10;
    int n, c, j;
    cin>>s;
    n = s.length();
    cin>>a>>b;
    arem[0] = (s[0]-48)%a;
    brem[n-1] = (s[n-1]-48)%b;
    pow10 = 10%b;
    loop(pos, 1, n)
    {
        arem[pos] = (arem[pos-1]*10 + s[pos]-48)%a;
        brem[n-pos-1] = (pow10*(s[n-pos-1]-48) + brem[n-pos])%b;
        pow10 = (pow10*10)%b;
    }
    bool f = 0;
    loop(pos, 0, n-1)
        if(arem[pos]==0 && brem[pos+1]==0)
        {j = pos+1, f = 1; break;}
    if(!f){cout<<"NO\n";return 0;}
    while(s[j]=='0'&&j<n)j++;
    if(j==n){cout<<"NO\n";return 0;}
    cout<<"YES\n";
    loop(i, 0, j)cout<<s[i];
    cout<<endl;
    loop(i, j, n)cout<<s[i];
    return 0;
}
