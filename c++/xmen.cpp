#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = 1000000000;
int main()
{
    int t, n, a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> b(n+1);
        vector<int> c(n+1);
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            c[a] = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            b[i] = c[a];
        }

        vector<int> d(n+1, INF);
        for (int i = 0; i < n; i++)
            *lower_bound(d.begin(), d.end(), b[i]) = b[i];
        for (int i = 0; i <= n; i++)
        {
            if (d[i] == INF)
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}