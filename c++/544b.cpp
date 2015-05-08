/*
Author: aseemraj
Problem: 544B
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
    int n, k, last[105], lastrow;
    char region[105][105];
    cin>>n>>k;
    loop(i, 0, n)loop(j, 0, n)region[i][j]='S';
    loop(i, 0, 105)last[i]=n;
    if(k>(n*n+1)/2)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        loop(i, 0, n)
        {
            if(k==0)break;
            loop(j, 0, n)
            {
                if(!((i+j)&1))
                {
                    region[i][j] = 'L';
                    k--;
                    last[j] = i;
                    if(k==0)break;
                }
            }
            lastrow = i;
        }
        if(n==1 && k==1)
            region[0][0] = 'L';

        loop(i, 0, n)
        {
            loop(j, 0, n)
                cout<<region[i][j];
            cout<<"\n";
        }
    }
    
    return 0;
}
