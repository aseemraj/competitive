/*
Author: aseemraj
Problem: RANKLIST
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

ll sum[100005];
ll n, s;

int justbelowidx()
{
    int st = 1, en = n, mid;
    while(st<=en)
    {
        mid = (st+en)/2;
        if(sum[mid] < s)
            st = mid+1;
        else if(sum[mid] > s)
            en = mid-1;
        else
            break;
    }
    while(s-sum[mid] < n-mid)mid--;
    return mid;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    loop(i, 1, 100005)sum[i]=sum[i-1]+i;

    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        if((n*(n+1))/2 == s){cout<<0<<endl;continue;}
        cout<<n-justbelowidx()<<endl;
    }
    return 0;
}
