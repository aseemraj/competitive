/*
Author: aseemraj
Problem: SIGNWAVE
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    ll t, s, c, k, tots, totc;
    cin>>t;
    while(t--)
    {
        cin>>s>>c>>k;
        if(s<k)tots=0;
        else tots=(1LL<<(s-k+1))+1;
        cout<<tots<<"\n";
    }
    return 0;
}