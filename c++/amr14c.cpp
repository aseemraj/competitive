/*
Author: noobsforever
Problem: amr14c
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m, x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            a[i] = a[i]%m;
        }

        sort(a, a+n);

        
    }
    return 0;
}
