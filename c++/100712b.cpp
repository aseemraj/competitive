/*
Author: aseemraj
Problem: 100712b
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
int rock[1005], paper[1005], scissor[1005];

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    string b;
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        loop(i, 0, n)
        {
            if(b[i] == 'R')
                rock[i + 1] = rock[i], paper[i + 1] = paper[i] + 1, scissor[i + 1] = scissor[i] - 1;
            else if(b[i] == 'P')
                rock[i + 1] = rock[i] - 1, paper[i + 1] = paper[i], scissor[i + 1] = scissor[i] + 1;
            else
                rock[i + 1] = rock[i] + 1, paper[i + 1] = paper[i] - 1, scissor[i + 1] = scissor[i];
        }

        int cnt = 0, k;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; i + j <= n; j++)
            {
                k = n - (i + j);
                if(rock[i] + paper[i+j] - paper[i] + scissor[i+j+k] - scissor[i+j] > 0)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}
