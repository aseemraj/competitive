#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#define all(c) c.begin(), c.end()
#define ll long long
using namespace std;
const unsigned int MAX = 1000002;
ll n, q, x, y;
ll sum[MAX];
ll tree[MAX];
ll tellsum(ll index)
{
    ll sum = 0;
    while(index>0)
    {
        sum += tree[index];
        index -= index&(-index);
    }
    return sum;
}

void update(ll index, ll val)
{
    while(index<n)
    {
        tree[index] += val;
        index += index&(-index);
    }
}
int main()
{
    sum[0] = 0;
    tree[0] = 0;
    char c;
    cin>>n>>q;
    int a[n+1];
    ll i;
    cin>>a[1];
    sum[1] = a[1];
    for(i=2;i<=n;i++)
    {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
    }
    for(i=1;i<=n;i++)
    {
        tree[i] = sum[i] - sum[i-(i&-i)];
    }

    while(q--)
    {
        cin>>c>>x>>y;
        x++;
        y++;
        if(c=='S')
        {
            cout<<tellsum(y)-tellsum(x-1)<<endl;
        }
        else if(c=='G')
        {
            y--;
            update(x, y);
        }
        else if(c=='T')
        {
            y--;
            update(x, -y);
        }
    }
    return 0;
}
