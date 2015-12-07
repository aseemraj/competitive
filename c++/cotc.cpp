/*
Author: aseemraj
Problem: cot
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
const int MAXN = 100005;
struct node
{
    int cnt;
    node *LEFT;
    node *RIGHT;
    node();
    node(int a,node *b,node *c);
};
node :: node()
{
    cnt = 0;
    LEFT = NULL;
    RIGHT = NULL;
}
node :: node(int a,node *b,node *c)
{
    cnt = a;
    LEFT = b;
    RIGHT = c;
}

int n, m, x, y;
int maxi;
PI v[MAXN];
int RM[MAXN], vv[MAXN];
VI adj[MAXN];
node *root[MAXN];
node *null;
int par[MAXN][20];
int depth[MAXN];

node* build_persistent_ST(node *par, int B, int E, int num)
{
    if(B <= num && num <= E)
    {
        node *trav;
        if(B == E)
        {
            trav = new node(par->cnt+1,null,null);
            return trav;
        }
        trav = new node;
        int mid;
        mid = (B + E)>>1;
        if(num <= mid)
        {
            trav->RIGHT = par->RIGHT;
            trav->LEFT = build_persistent_ST(par->LEFT,B,mid,num);
        }
        else
        {
            trav->LEFT = par->LEFT;
            trav->RIGHT = build_persistent_ST(par->RIGHT,mid+1,E,num);
        }
        trav->cnt = trav->LEFT->cnt + trav->RIGHT->cnt;
        return trav;
    }

    return null;
}

void dfs(int curr, int prev)
{
    par[curr][0] = prev;

    if(prev == -1)
        depth[curr] = 0;
    else
        depth[curr] = depth[prev] + 1;

    if(prev == -1)
        root[curr] = build_persistent_ST( null, 0, maxi-1, v[curr].S);
    else
        root[curr] = build_persistent_ST( root[prev], 0, maxi-1, v[curr].S);

    for(VI::iterator it = adj[curr].begin(); it != adj[curr].end(); it++)
        if(*it != prev)
            dfs(*it, curr);
}
int LCA(int n1, int n2)
{
    if(depth[n1] < depth[n2])
        return LCA(n2, n1);
    int diff = depth[n1] - depth[n2];

    loop(i, 0, 20)
    {
        if((diff>>i)&1)
            n1 = par[n1][i];
    }
    if(n1 != n2)
    {
        for(int i = 19; i >= 0; i--)
        {
            if(par[n1][i] != par[n2][i])
            {
                n1 = par[n1][i];
                n2 = par[n2][i];
            }
        }
        n1 = par[n1][0];
        n2 = par[n2][0];
        // now n1 = n2
    }
    return n1;
}

void test(node *trav, int B, int E)
{
    if(trav == null)
        return;
    int M;
    M = (B + E)>> 1;
    printf("%d %d %d\n", trav->cnt, B, E);
    test(trav->LEFT,B,M);
    test(trav->RIGHT,M+1,E);
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k)
{
    if(l==r)
        return l;

    int cnt = a->LEFT->cnt + b->LEFT->cnt - c->LEFT->cnt - d->LEFT->cnt;
    int mid = (l+r)>>1;
    if(cnt >= k)
        return query(a->LEFT, b->LEFT, c->LEFT, d->LEFT, l, mid, k);
    return query(a->RIGHT, b->RIGHT, c->RIGHT, d->RIGHT, mid+1, r, k-cnt);
}

int main()
{
    null = new node;
    null->cnt = 0;
    null->LEFT = null;
    null->RIGHT = null;
    scanf("%d %d", &n, &m);
    loop(i, 0, n)
    {
        scanf("%d", &vv[i]);
        v[i].F = vv[i];
    }
    sort(vv, vv + n);

    maxi = 0;
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && vv[i] == vv[i-1])
            continue;
        RM[maxi] = vv[i];
        maxi++;
    }
    for(int i = 0;i < n;i++)
    {
        v[i].S = lower_bound(RM,RM + maxi,v[i].F) - RM;
    }

    loop(i, 0, n-1)
    {
        scanf("%d %d", &x, &y);
        x--, y--;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    dfs(0, -1);
    for(int lvl = 1;lvl < 20;lvl++)
    {
        for(int i = 0;i < n;i++)
        {
            int tmp = par[i][lvl-1];
            if(tmp != -1)
                par[i][lvl] = par[tmp][lvl-1];
            else
                par[i][lvl] = -1;
        }
    }
    int k;
    node *a, *b, *c, *d;
    int _lca,ans;
    while(m--)
    {
        scanf("%d %d %d", &x, &y, &k);
        x--, y--;
        a = root[x];
        b = root[y];
        _lca = LCA(x,y);
//        printf("\nLCA: %d\n", _lca);
        c = root[_lca];
        if(par[_lca][0] == -1)
            d = null;
        else
            d = root[par[_lca][0]];
        ans = query(a,b,c,d,0,maxi-1,k);
        printf("%d\n", RM[ans]);
    }
//    loop(i , 0, n)
//    {
//        printf("*****TREE OF %d\n", v[i].S);
//        test(root[i],0,maxi-1);
//        printf("*****DONE********\n");
//    }
    return 0;
}
