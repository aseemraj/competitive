#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
const int MX = 1000007;
const int MAX = 1<<((int)ceil(log2(MX))+1);

struct node
{
    ll rmd[3], sum;
    node()
    {
        rmd[0] = 0;
        rmd[1] = 0;
        rmd[2] = 0;
        sum = 0;
    }
};

string str;
node tree[MAX];

node push(node l, node r)
{
    node t;
    t.sum = (l.sum + r.sum)%3;
    loop(i, 0, 3)
    {
        t.rmd[i] += l.rmd[i];
        t.rmd[(i+l.sum)%3] += r.rmd[i];
    }
    return t;
}
void build(int root, int l , int r)
{
    if(l==r)
    {
        tree[root].sum = (str[l-1]-48)%3;
        tree[root].rmd[tree[root].sum] = 1;
        tree[root].rmd[(tree[root].sum+1)%3] = 0;
        tree[root].rmd[(tree[root].sum+2)%3] = 0;
        return;
    }
    int mid = (l+r)/2;
    int left = (root*2);
    int right = left + 1;
    build(left,l,mid);
    build(right,mid+1,r);
    tree[root] = push(tree[left],tree[right]);
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
        return push(pl, pr);
    }
}
void update(int root, int l, int r, int x, int val)
{
    if(x<l or x>r) return ;
    if(l==r)
    {
        tree[root].sum = (val)%3;
        tree[root].rmd[tree[root].sum] = 1;
        tree[root].rmd[(tree[root].sum+1)%3] = 0;
        tree[root].rmd[(tree[root].sum+2)%3] = 0;
        return ;
    }
    int mid = (l+r)/2;
    int left = (root*2);
    int right = left + 1;
    if(x<=mid) update(left,l,mid,x,val);
    else update(right,mid+1,r,x,val);
    tree[root] = push(tree[left],tree[right]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, q, c, a, b;
    cin>>n>>q>>str;
    build(1,1,n);
    loop(i, 0, q)
    {
        cin>>c>>a>>b;
        if(c==1)
            update(1, 1, n, a, b);
        else
        {
            node res = query(1,1,n,a,b);
            ll total = 0, temp;
            loop(i, 0, 3)
            {
                temp = res.rmd[i];
                if(i==0)temp++;
                total += (temp*(temp-1))/2;
            }
            cout<<total<<endl;
        }
    }
    return 0;
}