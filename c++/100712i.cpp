/*
Author: aseemraj
Problem: 100712d
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define rloop(i, a, b) for(i=b-1; i>=a; i--)
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
    int t, n, add, cur, need, i, k, d;
    string s;
    bool ans;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n = s.length();
        rloop(k, 1, n+1)
        {
            loop(d, 0, 10)
            {
                ans = true;
                add = 0;
                int rem[251] = {0};
                for(i = 0; i+k <= n; i++)
                {
                    add -= rem[i];
                    cur = (s[i] - 48 + add) % 10;
                    need = (10 - cur + d) % 10;
                    add += need;
                    rem[i+k] = need;
                }
                while(i<n)
                {
                    // cout<<s[i]<<' '<<add<<' '<<rem[i]<<"\n";
                    add -= rem[i];
                    if((s[i] - 48 + add)%10 != d)
                    {
                        ans = false;
                        break;
                    }
                    i++;
                }
                if(ans) break;
            }
            if(ans) break;
        }
        cout<<k<<"\n";
    }
    return 0;
}
