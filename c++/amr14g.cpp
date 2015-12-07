/*
Author: noobsforever
Problem: amr14g
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;

ll power(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret = (ret*a) % MOD;
        a=(a*a) % MOD;
        b /= 2;
    }
    return ret;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

ll n, m;

bool possible(ll x)
{
    ll ancestors = 0, T = x;

    while(x > 1)
    {
        ancestors++;
        x/=2;
    }

    if(ancestors >= m)
        return 0;

    ll children = 0;
    x = T;
    ll left = 2*x, right = 2*x + 1;

    while(left<=n)
    {
        if(right>n)
            children += n-left+1;
        else
            children += right-left+1;
        right = right*2+1;
        left *= 2;
    }

    if(children > n-m)
        return 0;
    return 1;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        scanf("%lld%lld",&n,&m);

        ll lower, higher;
        lower = higher = m;


        ll low, high, mid;
        low = 1, high = m;

        while(low <= high)
        {
            mid=(low+high)/2;

            if(possible(mid))
            {
                lower=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }

        low = m, high = n;

        while(low <= high)
        {
            mid=(low+high)/2;

            if(possible(mid))
            {
                higher=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        //cout<<lower<<" "<<higher<<endl;
        printf("%lld\n",higher-lower+1);
    }
    return 0;
}
