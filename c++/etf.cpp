/*
Author: aseemraj
Problem: etf
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int fi(int n)
{
    int ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i;
            while(n%i == 0)
                n /= i;
        }
    }
    if(n > 1)
        ans -= ans/n;
    return ans;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", fi(n));
    }
    return 0;
}
