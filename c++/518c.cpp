/*
Author: aseemraj
Problem: 518C
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

    int n, m, k, icons, tscr = 0, a, b, temp;
    ll g = 0;
    cin>>n>>m>>k;
    icons = n;

    while(icons>=k)
    {
        icons -= k;
        tscr++;
    }

    if(icons)tscr++, icons=0;
    
    PI loc[n];
    int pres[tscr+1][k];

    int j = 0, scr = 1;
    loop(i, 0, n)
    {
        if(j==k) scr++, j=0;
        cin>>a;
        loc[a] = PI(scr, j);
        pres[scr][j] = a;
        j++;
    }

    loop(i, 0, m)
    {
        cin>>b;
        g += loc[b].F;
        if(loc[b].F==1 && loc[b].S==0)continue;

        if(loc[b].S==0)
        {
            temp = pres[loc[b].F-1][k-1];
            loc[temp] = PI(loc[b].F, 0);
            pres[loc[b].F-1][k-1] = b;
            
            pres[loc[b].F][0] = temp;
            loc[b] = PI(loc[b].F-1, k-1);
        }
        
        else
        {
            temp = pres[loc[b].F][loc[b].S-1];
            loc[temp] = PI(loc[b].F, loc[b].S);
            pres[loc[b].F][loc[b].S-1] = b;
            
            pres[loc[b].F][loc[b].S] = temp;
            loc[b] = PI(loc[b].F, loc[b].S-1);
        }
    }
    cout<<g<<"\n";

    return 0;
}