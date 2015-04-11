/*
Author: aseemraj
Problem: BROKPHON
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
    int t, n, x, y, c;
    cin>>t;
    while(t--)
    {
        c = 0;
        cin>>n;
        bool faulty[100000] = {0};
        cin>>x;
        loop(i, 1, n)
        {
            cin>>y;
            if(y!=x)faulty[i-1] = 1, faulty[i] = 1, x = y;
        }
        loop(i, 0, n)if(faulty[i])c++;
        cout<<c<<"\n";
    }
    return 0;
}
