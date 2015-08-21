/*
Author: aseemraj
Problem: 568A
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
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
const int MAXN = 2000005;
bool notprime[MAXN + 5];
int primesNoMoreThan[MAXN + 5];
int palinsNoMoreThan[MAXN + 5];

bool isPalindrome(int x)
{
    int rx = x, t = 0;
    while(rx)
    {
        t = t*10 + (rx%10);
        rx /= 10;
    }
    return x == t;
}



int main()
{
    ios_base::sync_with_stdio(0);
    int p, q, k, primes = 0;
    cin>>p>>q;

    notprime[1] = 1;
    k = sqrt(MAXN + 0.5);
    loop(i, 2, k+1)
        if(!notprime[i])
            loopinc(j, 2*i, MAXN, i)
                notprime[j] = true;
    
    loop(i, 1, MAXN)
    {
        palinsNoMoreThan[i] = palinsNoMoreThan[i-1] + isPalindrome(i);
        if(!notprime[i])primes++;
        primesNoMoreThan[i] = primes;
    }

    // loop(f, 1, 50)
    //     cout<<"pi("<<f<<"): "<<primesNoMoreThan[f]<<", s: "<<palinsNoMoreThan[f]<<' '<<isPalindrome(f)<<"\n";
    rloop(i, 1, MAXN)
    {
        if(q*primesNoMoreThan[i] <= p*palinsNoMoreThan[i])
        {
            cout<<i<<"\n";
            return 0;
        }
    }

    
    return 0;
}
