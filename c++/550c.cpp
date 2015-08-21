/*
Author: aseemraj
Problem: 550C
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
    string s;
    cin>>s;
    int n = s.size(), m;
    loop(i, 0, n)
    {
        m = s[i]-48;
        if(m%8==0)
        {
            cout<<"YES\n"<<m;
            return 0;
        }
        loop(j, i+1, n)
        {
            m = (s[i]-48)*10 + s[j]-48;
            if(m%8==0)
            {
                cout<<"YES\n"<<m;
                return 0;
            }
            loop(k, j+1, n)
            {
                m = (s[i]-48)*100 + (s[j]-48)*10 + s[k]-48;
                if(m%8==0)
                {
                    cout<<"YES\n"<<m;
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}
