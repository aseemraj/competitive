/*
Author: aseemraj
Problem: SBSTR1
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
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;
bool nprime[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    string a, b;
    bool f, found;
    loop(i, 0, 24)
    {
        cin>>a>>b;
        found = 0;
        loop(i, 0, 5)
        {
            f = 0;
            loop(j, i, i+5)
            {
                if(a[j]!=b[j-i])
                {
                    f = 1;
                    break;
                }
            }
            if(!f)
            {
                found = 1;
                break;
            }
        }
        if(found)cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}
