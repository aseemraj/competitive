/*
Author: aseemraj
Problem: QCHEF
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
const int MAX = 100005;

int g[MAX], mx[MAX+5], mn[MAX+5];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k, l, r;
    cin>>n>>m>>k;
    loop(i, 0, n)
    {
        cin>>g[i];
        mx[i+1] = max(mx[i], g[i]);
        mn[i+1] = min(mn[i], g[i]);
    }

    loop(i, 0, k)
    {
        cin>>a>>b;
        node res = query(1, 1, n, a, b);
        cout<<res.val<<endl;
    }
    return 0;
}