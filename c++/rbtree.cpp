#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lg(ll n){ll c = 0;while(n>>=1)c++;return c;}
int main()
{
    ios_base::sync_with_stdio(0);
    ll q, p1, p2, x, y, ansb, ansr;
    bool stat = true;
    string s;
    cin>>q;
    while(q--)
    {
        cin>>s;
        if(s[1]=='i')stat=!stat;
        else
        {
            cin>>x>>y;
            p1 = x, p2 = y;
            while(p1!=p2)
            {
                if(p1>p2)p1>>=1;
                else if(p1<p2)p2>>=1;
            }
            ansb = ((lg(p1)&1)^(stat))?((lg(x)-lg(p1))/2+(lg(y)-lg(p2))/2+1):((lg(x)-lg(p1)+1)/2+(lg(y)-lg(p1)+1)/2);
            ansr = ((lg(p1)&1)^(stat))?((lg(x)-lg(p1)+1)/2+(lg(y)-lg(p1)+1)/2):((lg(x)-lg(p1))/2+(lg(y)-lg(p2))/2+1);
            if(s[1]=='b')cout<<ansb<<endl;
            else cout<<ansr<<endl;
        }
    }
    return 0;
}
