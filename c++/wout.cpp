/*
Author: aseemraj
Problem: wout
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
int a[1000005];
int c[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, l, h, cur;
    ll sum, mn;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum = 0;
        loop(i, 0, n+1)a[i] = 0;
        loop(i, 0, n)
        {
            cin>>l>>h;
            a[l]--;
            a[h+1]++;
        }
        cur = n;
        loop(i, 0, n)
        {
            cur = cur + a[i];
            c[i] = cur;
        }
        list<int> ls;
        loop(i, 0, k)
        {
            ls.push_back(c[i]);
            sum += c[i];
        }
        mn = sum;
        loop(i, k, n)
        {
            sum = sum - ls.front() + c[i];
            ls.pop_front();
            ls.push_back(c[i]);
            mn = min(mn, sum);
        }
        cout<<mn<<"\n";
    }
    
    return 0;
}
