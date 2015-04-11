/*
Author: aseemraj
Problem: 515B
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

    int n, m, b, g, x;
    cin>>n>>m;
    int bh[105] = {0};
    int gh[105] = {0};
    cin>>b;
    loop(i, 0, b){cin>>x;bh[x]=true;}
    cin>>g;
    loop(i, 0, g){cin>>x;gh[x]=true;}
    
    loop(i, 0, 2*m*n+1)
    {
        if(gh[i%m])bh[i%n]=true;
        else if(bh[i%n])gh[i%m]=true;
    }

    bool f = 0;
    
    loop(i, 0, n)if(!bh[i]){f=1;break;}
    loop(i, 0, m)if(!gh[i]){f=1;break;}

    if(f)cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}