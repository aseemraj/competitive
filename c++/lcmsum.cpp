/*
Author: aseemraj
Problem: lcmsum
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll fi[1000005];
ll ans[1000005];

void prestorefi(int n)
{
    for(int i = 1; i <= n; i++)
        fi[i] = i;
    for(int i = 2; i <= n; i++)
        if(fi[i] == i)
            for(int j = i; j <= n; j += i)
                fi[j] -= fi[j]/i;

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i)
            ans[j] += (i * fi[i]);
}

int main()
{
    // ios_base::sync_with_stdio(0);
    prestorefi(1000001);
    int t;
    ll n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", ((ans[n]+1)*n)/2);
    }
    return 0;
}
