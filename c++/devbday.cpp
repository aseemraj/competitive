/*
Author: aseemraj
Problem: devbday
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    ll ans = 0;
    cin>>t;
    while(t--)
    {
        bool visited[100005] = {0};
        ans = 0;
        cin>>n;
        int f[n+1];
        ll r[n+1];
        loop(i, 1, n+1)cin>>f[i];
        loop(i, 1, n+1)cin>>r[i];

        ll profit = 0;
        int j;
        loop(i, 1, n+1)
        {
            if(visited[i])continue;
            visited[i] = 1;
            profit = r[i];
            j = f[i];
            while(j!=i)
            {
                visited[j] = 1;
                profit += r[j];
                j = f[j];
            }
            ans = max(ans, profit);
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
