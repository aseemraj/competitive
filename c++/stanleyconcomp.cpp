/*
Author: aseemraj
Problem: stanleyconcomp
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

const int INF = 1000000000;
int w[200005];
int par[200005];
int sz[200005];

multiset<int> weights;

// Return the par of component corresponding to node p
int ffind(int p)
{
    int root = p;
    while (root != par[root])
        root = par[root];
    while (p != root)
    {
        int newp = par[p];
        par[p] = root;
        p = newp;
    }
    return root;
}

// Replace sets containing x and y with their union
void merge(int x, int y)
{
    int i = ffind(x);
    int j = ffind(y);
    if(i == j) return;
    
    // make smaller root point to larger one
    if(sz[i] < sz[j])
    {
        par[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        par[j] = i;
        sz[i] += sz[j];
    }
}

// Are objects x and y in the same set?
bool connected(int x, int y)
{
    return ffind(x) == ffind(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, q, u, v, p1, p2, wt, mn;
    cin>>n>>q;
    mn = INF;
    loop(i, 1, n+1)
    {
        cin>>w[i];
        weights.insert(w[i]);
        par[i] = i;
        sz[i] = 1;
        mn = min(mn, w[i]);
    }
    while(q--)
    {
        cin>>u>>v;
        if(connected(u, v))
        {
            cout<<mn<<"\n";
            continue;
        }
        p1 = ffind(u);
        p2 = ffind(v);
        wt = w[p1] + w[p2];
        
        weights.erase(weights.find(w[p1]));
        weights.erase(weights.find(w[p2]));

        merge(u, v);

        p1 = ffind(u);

        w[p1] = wt;
        weights.insert(wt);

        mn = *(weights.begin());
        cout<<mn<<"\n";
    }
    return 0;
}
