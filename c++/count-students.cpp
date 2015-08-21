/*
Author: aseemraj
Problem: find-students
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
    int n, c, t, k;
    int mn = INT_MAX;
    cin>>n;
    c = n;
    int a[n];
    loop(i, 0, n)
    {
        cin>>a[i];
        mn = min(mn, a[i]);
    }
    
    while(c)
    {
        t = INT_MAX;
        k = 0;
        loop(i, 0, n)
        {
            if(a[i]==0)continue;
            a[i] -= mn;
            k++;
            if(a[i]==0)c--;
            else t = min(t, a[i]);
        }
        mn = t;
        cout<<k<<"\n";
    }
    
    return 0;
}
