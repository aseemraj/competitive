/*
Author: aseemraj
Problem: CHCUBE
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
    int t;
    cin>>t;
    string s;
    string colors[6] = {"black", "blue", "red", "green", "yellow", "orange"};
    while(t--)
    {
        map<string, bool> col[3];
        loop(i, 0, 6)
        {
            cin>>s;
            col[i/2][s] = 1;
        }
        bool f;
        loop(j, 0, 6)
        {
            f = 1;
            loop(i, 0, 3)
            {
                if(!col[i][colors[j]])
                {
                    f = 0;
                    break;
                }
            }
            if(f)
            {
                cout<<"YES\n";
                break;
            }
        }
        if(!f)
            cout<<"NO\n";
    }
    
    return 0;
}
