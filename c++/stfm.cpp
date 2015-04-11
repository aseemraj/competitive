/*
Author: aseemraj
Problem: STFM
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define VI V(int)
#define VP V(PI)

typedef long long ll;
using namespace std;

ll fac[10000005];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    ll p, t1, t2, ans=0;
    fac[0] = 1;
    loop(i, 1, m)
        fac[i] = fac[i-1]*i % m;
    loop(i, 0, n)
    {
        cin>>p;
        if(p<m-1)
        {
            t1 = fac[p+1]-1;
            if(p&1)t2 = ((((((p+1)/2)%m)*p)%m)*p)%m;
            else t2 = (((((p/2)%m)*p)%m)*(p+1))%m;
            ans += (t1+t2)%m;
            if(ans>=m)ans%=m;
        }
        else
        {
            if(p&1)t2 = ((((((p+1)/2)%m)*(p%m))%m)*(p%m))%m;
            else t2 = (((((p/2)%m)*(p%m))%m)*((p+1)%m))%m;
            ans += (t2-1)%m;
            if(ans>=m)ans%=m;
        }
    }
    cout<<(ans+m)%m<<endl;
    return 0;
}
