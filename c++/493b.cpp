#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, last=0;
    cin>>n;
    vector<ll> f;
    vector<ll> s;
    ll a, ft=0, st=0;
    loop(i, 0, n)
    {
        cin>>a;
        if(a>0){f.push_back(a);ft+=a;last=1;}
        else{s.push_back(-a);st-=a;last=2;}
    }
    if(ft>st){cout<<"first\n";return 0;}
    else if(ft<st){cout<<"second\n";return 0;}
    else
    {
        loop(i, 0, min(f.size(), s.size()))
        {
            if(f[i]>s[i]){cout<<"first\n";return 0;}
            else if(f[i]<s[i]){cout<<"second\n";return 0;}
        }
        if(last==1)cout<<"first\n";
        else if(last==2)cout<<"second\n";
    }
    return 0;
}
