/*
Author: aseemraj
Problem: CHEFCH
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define VI V(int)
#define VP V(PI)

typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, p;
    char c;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n = s.size();
        c = s[0], p = 0;
        loop(i, 1, n)
        {
            if(s[i]==c)
            {
                if(p+1 <= i-p)
                {
                    p++;
                    c = c=='+'?'-':'+';
                }
                else p = i-p;
            }
            else c=s[i];
        }
        cout<<p<<endl;
    }
    return 0;
}
