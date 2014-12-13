#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    string s, t;
    cin>>s>>t;
    int sh = (s[0]-48)*10 + s[1]-48;
    int th = (t[0]-48)*10 + t[1]-48;
    int sm = (s[3]-48)*10 + s[4]-48;
    int tm = (t[3]-48)*10 + t[4]-48;
    int stot = sh*60 + sm;
    int ttot = th*60 + tm;
    int ptot = (stot + 1440 - ttot)%1440;
    int ph = (ptot)/60;
    int pm = (ptot)%60;
    if(ph/10==0)
        cout<<"0";
    cout<<ph<<":";
    if(pm/10==0)
        cout<<"0";
    cout<<pm<<endl;
    return 0;
}
