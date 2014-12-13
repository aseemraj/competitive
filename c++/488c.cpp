#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int hy, ay, dy, hm, am, dm, h, a, d, km, ky;
    cin>>hy>>ay>>dy>>hm>>am>>dm;
    cin>>h>>a>>d;
    ky = max(0, am-dy);
    km = max(0, ay-dm);
    if(ky==0 && km>0){cout<<0<<endl;return 0;}
    else if(ky==0 && km==0)cout<<min(h, a*(dm-ay+1))<<endl;
    else if(ky>0 && km>0)
    {
        ty = hy/ky;
        tm = hm/km;
        if(hy%ky==0)ty++;
        if(hm%km==0)tm++;
        if(ty>tm)cout<<0<<endl;
        else
        {

        }
    }
    return 0;
}
