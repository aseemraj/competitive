#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
bool has8(ll x)
{
    x = abs(x);
    while(x>0)
    {
        if(x%10==8)return true;
        x/=10;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll a;
    int c = 1;
    cin>>a;
    a++;
    c = 1;
    while(!has8(a))
    {
        a++;
        c++;
    }
    cout<<c<<endl;
    return 0;
}
