/*
Author: aseemraj
Problem: 100712j
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
    int t, n, m, x;
    cin>>t;
    while(t--)
    {
        VI age(100, 0);
        VI can(100, 0);
        cin>>n>>m;
        loop(i, 0, n)
        {
            cin>>x;
            age[x]++;
        }
        loop(i, 0, m)
        {
            cin>>x;
            can[x]++;
        }

        int j = 1;
        bool ans = 1;
        loop(i, 5, 16)
        {
            if(age[i]>0)
            {
                while(j <= 50 && can[j] < age[i])j++;
                if(j>50)
                {
                    ans = 0;
                    break;
                }
                j++;
            }
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}