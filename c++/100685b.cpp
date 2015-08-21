/*
Author: aseemraj
Problem: 
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

// #define SUBLIME
#if defined SUBLIME
#  define ISTREAM ifile
#else
#  define ISTREAM cin
#endif

typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined (SUBLIME)
      ifstream ifile("test.input");
    #endif
    int n, A, B, toUse, idx;
    cin>>n>>A>>B;
    int a[n], b[n], c[n];
    loop(i, 0, n)cin>>a[i];
    loop(i, 0, n)cin>>b[i];

    loop(i, 0, n)c[i]=a[i]+b[i];

    PI tickets[2];
    // F = number of times used
    // S = first index (0 based) on which it was used
    tickets[0].F = tickets[1].F = 0;
    tickets[0].S = tickets[1].S = 0;

    int cnt = 0;
    loop(i, 0, n)
    {
        if(c[i] == 2)
        {
            loop(j, 0, 2)
            {
                if(tickets[j].F > 0 && tickets[j].F < A && i - tickets[j].S < B)
                    tickets[j].F++;
                else
                {
                    tickets[j].F = 1;
                    tickets[j].S = i;
                    cnt++;
                }
            }
        }
        else if(c[i] == 1)
        {
            toUse = -1;
            idx = 500;
            loop(j, 0, 2)
            {
                if(tickets[j].F > 0 && tickets[j].F < A && i - tickets[j].S < B)
                {
                    if(tickets[j].S < idx)
                    {
                        idx = tickets[j].S;
                        toUse = j;
                    }
                }
            }
            if(toUse == -1)
            {
                tickets[0].F = 1;
                tickets[0].S = i;
                cnt++;
            }
            else
                tickets[toUse].F++;
        }
    }
    cout<<cnt<<"\n";
    
    return 0;
}
