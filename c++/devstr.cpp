/*
Author: aseemraj
Problem: devstr
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
    int t, n, k, c, cnt, beg;
    char x;
    string s;
    cin>>t;
    while(t--)
    {
        c = cnt = 0;
        cin>>n>>k>>s;
        if(k==1)
        {
            int c1 = 0, c2 = 0;
            loop(i, 0, n)
            {
                if(i&1)
                    c1 += s[i] - '0', c2 += '1' - s[i];
                else
                    c1 += '1' - s[i], c2 += s[i] - '0';
            }
            if(c1 < c2)
            {
                cout<<c1<<"\n";
                loop(i, 0, n)
                {
                    if(i&1)cout<<0;
                    else cout<<1;
                }
                cout<<"\n";
            }
            else
            {
                cout<<c2<<"\n";
                loop(i, 0, n)
                {
                    if(i&1)cout<<1;
                    else cout<<0;
                }
                cout<<"\n";
            }
            continue;
        }
        x = s[0];
        c = 1;
        beg = 0;
        int cnt = 0;
        loop(i, 1, n)
        {
            if(s[i]==x)c++;
            else
            {
                x = s[i];
                c = 1;
                beg = i;
            }
            if(c==k+1)
            {
                if(i+1<n && s[i+1]==x)
                    s[i] = '1' - s[i] + 48, x = s[i], cnt++;
                else if(i+1<n && s[i+1]!=x)
                    s[beg+k/2] = '1' - s[beg+k/2] + 48, x = s[i], cnt++;
                else
                    s[i] = '1' - s[i] + 48, cnt++;
            }
        }
        cout<<cnt<<"\n"<<s<<"\n";
    }
    return 0;
}