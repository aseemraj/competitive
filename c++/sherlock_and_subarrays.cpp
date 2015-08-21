/*
Author: aseemraj
Problem: sherlock and subarrays
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
#define Middle(x, y) (x + (y -x)/2)
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

ll sg[2][10000000];

PLL ExecuteQuery(ll as, ll ae, ll qs, ll qe, ll idx)
{
    if (qs <= as && qe >= ae)
        return make_pair(sg[0][idx], sg[1][idx]);
 
    if (ae < qs || as > qe)
        return make_pair(LONG_MIN, 0);
 
    ll mid = Middle(as, ae);
    PLL ans1, ans2;
    ans1 = ExecuteQuery(as, mid, qs, qe, 2*idx+1);
    ans2 = ExecuteQuery(mid+1, ae, qs, qe, 2*idx+2);
    if(ans1.F == ans2.F)
        return make_pair(ans1.F,ans1.S+ans2.S);
    else if(ans1.F > ans2.F)
        return ans1;
    else
        return ans2;
} 

ll FetchAnswer(ll n, ll qs, ll qe)
{
    return ExecuteQuery(0, n-1, qs, qe, 0).S;
}

PLL Build(ll arr[], ll as, ll ae, ll sidx)
{
    if (as == ae)
    {
        sg[0][sidx] = arr[as];
        sg[1][sidx]=1;
        return make_pair(arr[as],1);
    }

    ll mid = Middle(as, ae);
    PLL ans1,ans2;
    ans1 = Build(arr, as, mid, sidx*2+1);
    ans2 = Build(arr, mid+1, ae, sidx*2+2);
    if(ans1.F == ans2.F)
    {
        sg[0][sidx] = ans1.F;
        sg[1][sidx] = ans1.S + ans2.S;
        return make_pair(ans1.F, ans1.S + ans2.S);
    }
    else if(ans1.F > ans2.F)
    {
        sg[0][sidx] = ans1.F;
        sg[1][sidx] = ans1.S;
        return ans1;
    }
    else
    {
        sg[0][sidx] = ans2.F;
        sg[1][sidx] = ans2.S;
        return ans2;
    }
}

void BuildTree(ll arr[], ll n)
{
    Build(arr, 0, n-1, 0);
}

int main()
{
    ll n, m, ans1, ans2;
    cin>>n>>m;
    ll arr[n];
    
    loop(i, 0, n)
        cin>>arr[i];
    
    BuildTree(arr, n);
    
    loop(i, 0, m)
    {
        cin>>ans1>>ans2;
        ans1--, ans2--;
        cout<<FetchAnswer(n, ans1, ans2)<<endl;
    } 
    return 0;
}