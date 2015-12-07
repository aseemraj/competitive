/*
Author: noobsforever
Problem: amr14d
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, x;
    cin>>t;
    while(t--)
    {
        int a[1005] = {0};
        cin>>n;
        bool f = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>x;
            a[x]++;
            if(a[x] > 1)
                f = 1;
        }
        if(f)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
