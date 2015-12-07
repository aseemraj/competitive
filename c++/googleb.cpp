/*
Author: aseemraj
Problem: googleB
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
int main()
{
    int cases, n;
    cin>>cases;
    for (int t = 1; t <= cases; t++)
    {
        cin>>n;
        ll p[n], k[n], tot;
        ll lb, ub, t100 = -1;
        lb = 0, ub = INF;
        for(int i = 0; i < n; i++)
        {
            cin>>p[i]>>k[i];
            lb = max(lb, (k[i]*100)/(p[i] + 1));
            if(p[i] > 0)
                ub = min(ub, (k[i]*100)/p[i]);
            if(p[i] == 100)
                t100 = k[i];
        }
        cout<<"Case #"<<t<<": ";
        if(lb + 1 == ub)
            cout<<ub<<"\n";
        else if(t100 <= ub && t100 > lb)
            cout<<t100<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
