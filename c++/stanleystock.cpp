/*
Author: aseemraj
Problem: stanley and stocks
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

ll result = -1, z;

ll recur(ll a[],ll i,ll sum,ll n,ll mid)
{
    if(i==n)
    {
        result=max(result,sum);
        return 1;
    }
    else
    {
        ll temp=a[i];
        if((a[i-1]%2==0)&&(a[i+1]%2==0))
        {
            a[i]=(a[i-1]+a[i+1])/2;
            z= recur(a,i+1,sum-abs(temp-a[n-i])+abs(a[i]-a[n-i]),n,mid);
            a[i]=temp;
            
        }
        z= recur(a,i+1,sum,n,mid);
    }
    return 1;
}

ll recureven(ll a[],ll i,ll sum, ll n)
{
    if(i==n)
    {
        result=max(result,sum);
        return 1;
    }
    else
    {
        ll temp=a[i];
        if((a[i-1]%2==0)&&(a[i+1]%2==0))
        {
            ll tempsum;
            a[i]=(a[i-1]+a[i+1])/2;
            if((n+1)%2==0)
                tempsum =sum-abs(temp-a[n-i])+abs(a[i]-a[n-i]);
            else
            {
                if(i==((n+1)/2))
                    tempsum=sum;
                else
                    tempsum =sum-abs(temp-a[n-i])+abs(a[i]-a[n-i]);
            }          
            z= recureven(a,i+1,tempsum,n);
            a[i]=temp;
        }
        z = recureven(a,i+1,sum,n);
    }
    return 1;
    
}
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,sum=0,temp;
        scanf("%lld",&n);
        ll a[n+1], i;
        loop(i, 0, n)
            cin>>a[i];
        loop(i, 0, n/2)
        {
        	sum+=abs(a[i]-a[n-i-1]);
        }
    	
    	result=sum;
    	z=recureven(a,1,sum,n-1);
        printf("%lld\n",result);
        
    }
    return 0;
}
