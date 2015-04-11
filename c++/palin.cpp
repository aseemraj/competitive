/*
Author: aseemraj
Problem: PALIN
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

int main()
{
    ios_base::sync_with_stdio(0);

    int t, sz;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        sz = s.size();
        int j = sz-1;
        while(s[j]=='9' && j>=0)
            s[j] = '0', j--;
        if(j<0)
            s = "1"+s, sz++;
        else s[j]++;
        loop(i, 0, sz/2)
        {
            if(s[i]!=s[sz-1-i])
            {
                if(s[sz-1-i]<s[i])
                    s[sz-1-i] = s[i];
                else if(sz-2-i >= 0 && sz-2-i != i)
                {
                    s[sz-1-i] = s[i];
                    j = sz-2-i;
                    while(s[j]=='9')
                        s[j] = '0', j--;
                    s[j]++;
                    i--;
                }
                else if(sz-2-i == i)
                {
                    s[sz-1-i] = s[i]+1;
                    s[i]++;
                }
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
