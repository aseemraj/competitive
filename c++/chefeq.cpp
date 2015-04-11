/*
Author: aseemraj
Problem: CHEFEQ
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
    int t, n, ans, mx, a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int c[100005] = {0};
        mx = 0;
        loop(i, 0, n)
        {
            cin>>a;
            c[a]++;
            if(c[a]>mx){ans=a;mx=c[a];}
        }
        cout<<n-c[ans]<<endl;
    }
    return 0;
}
