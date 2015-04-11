
/*
Author: aseemraj
Problem: PRIME1 
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
bool nprime[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    ll m, n;
    loop(i, 2, 1000)
    {
        if(!nprime[i])
            for(int j=i*2; j<100000; j+=i)
                nprime[j]=1;
    }
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        bool ntprime[100005]={0};
        int sr = sqrt(n);
        loop(i, 2, sr+1)
        {
            if(!nprime[i])
            {
                int j = i*(m/i);
                while(j<m)j+=i;
                if(j==i)j+=i;
                for(; j<=n; j+=i)
                    ntprime[j-m]=1;
            }
        }
        loop(i, m, n+1)
        {
            if(i<2)continue;
            if(!ntprime[i-m])
                cout<<i<<"\n";
        }
        cout<<"\n";
    }    
    return 0;
}
