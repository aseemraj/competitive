/*
Author: aseemraj
Problem: 518B
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

    string s, t;
    cin>>s;
    int sz = s.size();
    cin>>t;
    int tz = t.size();
    int wanted[200] = {0};
    int present[200] = {0};
    int yay = 0, whoops = 0;

    loop(i, 0, tz) present[t[i]]++;
    loop(i, 0, sz) wanted[s[i]]++;

    loop(i, 65, 123)
    {
        if(wanted[i]<=0)continue;
        if(wanted[i] <= present[i])
        {
            yay += wanted[i];
            present[i] -= wanted[i];
            wanted[i] = 0;
        }
        else
        {
            yay += present[i];
            wanted[i] -= present[i];
            present[i] = 0;
        }
    }

    loop(i, 65, 91)
    {
        if(wanted[i]<=0)continue;
        if(wanted[i] <= present[i+32])
        {
            whoops += wanted[i];
            present[i+32] -= wanted[i];
            wanted[i] = 0;
        }
        else
        {
            whoops += present[i+32];
            wanted[i] -= present[i];
            present[i+32] = 0;
        }
    }

    loop(i, 97, 123)
    {
        if(wanted[i]<=0)continue;
        if(wanted[i] <= present[i-32])
        {
            whoops += wanted[i];
            present[i-32] -= wanted[i];
            wanted[i] = 0;
        }
        else
        {
            whoops += present[i-32];
            wanted[i] -= present[i];
            present[i-32] = 0;
        }
    }

    cout<<yay<<' '<<whoops<<"\n";
    return 0;
}