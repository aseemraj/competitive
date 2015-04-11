/*
Author: aseemraj
Problem: CHEFLCM
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    ll sum;
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin>>n;
        int rt = sqrt(n)+1;
        loop(i, 1, rt)
        {
            if(n%i==0)
            {
                if(i == n/i)sum+=i;
                else sum+=i+n/i;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
