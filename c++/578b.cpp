#include <bits/stdc++.h>

using namespace std;

long long a[200010];
long long LEFT[200010];
long long RIGHT[200010];
long long OR[200010];

int n,x,k;

int main()
{
    cin >> n >> k >> x;
    long long mul;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    LEFT[0] = 0;
    for(int i = 1;i < n;i++)
    {
        LEFT[i] = a[i-1] | LEFT[i-1];
    }

    RIGHT[n-1] = 0;
    for(int i = n-2;i >= 0;i--)
    {
        RIGHT[i] = a[i+1] | RIGHT[i +1];
    }
    mul = 1;
    for(int i=0; i<k; i++)
        mul *= x;
    
    for(int i = 0;i < n;i++)
    {
        OR[i] = LEFT[i] | RIGHT[i] | (a[i] * mul);
    }

    long long ans;
    ans = *(max_element(OR,OR+n));
    cout << ans << endl;
    return 0;
}