/*
Author: aseemraj
Problem: 516C
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

const int MAX = 400000;
ll h[100005];
ll a[100005];
ll d[100005];

struct node
{
    ll mx;
    int st, en;
    node()
    {
        st = 0;
        en = 0;
        mx = 0;
    }
};

node tree[MAX];

node push(node l, node r)
{
    node t;
    t.mx = l.mx - 2*h[l.en] + r.mx - 2*h[r.st] + d[r.st-l.en-1];
    t.st = l.st;
    t.en = r.en;
    // t.mx += h[l.st] + h[r.en];
    return t;
}
void build(int root, int l , int r)
{
    if(l==r)
    {
        tree[root].mx = 4*h[l-1];
        tree[root].st = l-1;
        tree[root].en = r-1;
        return;
    }
    int mid = (l+r)/2;
    int left = (root*2);
    int right = left + 1;
    build(left, l, mid);
    build(right, mid+1, r);
    tree[root] = push(tree[left], tree[right]);
    // cout<<l<<' '<<r<<' '<<tree[root].mx<<endl;
}
node query(int root, int l, int r, int x, int y)
{
    int mid = (l+r)/2;
    int left = root*2;
    int right = left + 1;
    if(x==l && y==r) return tree[root];
    if(y<=mid)return query(left, l, mid, x, y);
    else if(x>mid)return query(right, mid+1, r, x, y);
    else
    {
        node pl = query(left, l, mid, x, mid);
        node pr = query(right, mid+1, r, mid+1, y);
        // cout<<"testing: "<<l<<' '<<mid<<' '<<pl.mx<<endl;
        // cout<<"testing: "<<mid+1<<' '<<r<<' '<<pr.mx<<endl;

        return push(pl, pr);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m, a, b;
    ll ans;
    cin>>n>>m;
    loop(i, 0, n)cin>>d[i];
    loop(i, 0, n)cin>>h[i];
    build(1,1,n);

    // loop(i, 1, n+1)
    // {
    //     loop(j, i, n+1)
    //         cout<<i<<" to "<<j<<": "<<query(1, 1, n, i, j).mx<<endl;
    // }

    while(m--)
    {
        cin>>a>>b;
        if(a>b)
        {
            if(b+1==a-1)
            {
                cout<<2*h[a-1]<<"\n";
                continue;
            }
            ans = query(1, 1, n, b+1, a-1).mx;
            cout<<ans<<"\n";
        }
        else if(a<b && b==n)
        {
            ans = query(1, 1, n, 1, a-1).mx;
            cout<<ans<<"\n";
        }
        else if(a<b && a==1)
        {
            ans = query(1, 1, n, b+1, n).mx;
            cout<<ans<<"\n";
        }
        else
        {
            ll t1, t2;
            if(a>1)
                t1 = query(1, 1, n, 1, a-1).mx;
            if(a<n)
                t2 = query(1, 1, n, a+1, n).mx;
            if(a<n && a>1)ans = t1 + t2 - 2*h[n-1] - 2*h[0] + d[n];
            else if(a==1)
                ans = t2;
            else if(a==n)
                ans = t1;
            cout<<ans<<"\n";
        }
    }
    return 0;
}