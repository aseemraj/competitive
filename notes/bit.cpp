#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define LSOne(S) (S & (-S))
typedef long long ll;
using namespace std;
int maxVal;
ll tree[100005];
ll sum[100005];
ll read(int idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx, ll val)
{
    while (idx <= maxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, idx, q, c, x, st, en;
    ll y;
    cin>>n;
    ll a[n];
    maxVal = n+1;
    loop(i, 0, n)cin>>a[i];

    // Building tree
    loop(i, 1, n+1)
        update(i, a[i-1]);

    // Queries
    cin>>q;
    while(q--)
    {
        cin>>c;
        if(c==1) // Change a[x-1] to y
        {
            cin>>x>>y;
            y = y-a[x-1];
            a[x-1] += y;
            update(x, y);
        }
        else // sum from st to en
        {
            cin>>st>>en;
            cout<<read(en)-read(st-1)<<endl;
        }
    }
    return 0;
}
