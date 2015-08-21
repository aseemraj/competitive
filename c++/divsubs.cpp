/*
Author: aseemraj
Problem: divsubs
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
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, idx1, idx2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n], sum[n+1];
        int rem[100005] = {0};
        sum[0] = 0;
        loop(i, 0, n)
        {
            cin>>a[i];
            sum[i+1] = sum[i] + a[i];
        }
        sort(sum, sum+n+1);
        loop(i, 0, n+1)
        {
            if(rem[sum[i]%n]==0)
                rem[sum[i]%n] = i+1;
            else
            {
                idx1 = rem[sum[i]%n];
                idx2 = i+1;
                break;
            }
        }
        cout<<idx2-idx1<<"\n";
        loop(i, idx1, idx2)cout<<i<<' ';
        cout<<"\n";
    }
    
    return 0;
}
