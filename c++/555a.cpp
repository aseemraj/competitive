/*
Author: aseemraj
Problem: 555a
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

VI chains[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, m, x, steps = 0, pieces = 0;
    cin>>n>>k;

    loop(i, 0, k)
    {
        cin>>m;
        loop(j, 0, m)
        {
            cin>>x;
            chains[i].PB(x);
        }
        int j = 0;
        if(chains[i][j]>1)
        {
            pieces += m;
            steps += m-1;
            continue;
        }
        while(j<m-1 && chains[i][j] + 1 == chains[i][j+1])
            j++;

        pieces += m-j;
        steps += m-1-j;
    }

    steps += pieces - 1;
    cout<<steps<<"\n";
    
    return 0;
}
