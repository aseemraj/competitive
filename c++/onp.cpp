/*
Author: aseemraj
Problem: OPN
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
int prec(char x)
{
    if(x=='(')return -1;
    if(x=='^')return 4;
    if(x=='/')return 3;
    if(x=='*')return 2;
    if(x=='-')return 1;
    if(x=='+')return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, sz;
    string s;
    string out;
    cin>>t;
    while(t--)
    {
        cin>>s;
        stack<char> op;
        sz = s.size();
        out = "";
        loop(i, 0, sz)
        {
            if(s[i]=='(')
                op.push(s[i]);
            else if(s[i]==')')
            {
                while(op.top() != '(')
                {
                    out+=op.top();
                    op.pop();
                }
                op.pop();
            }
            else if(s[i]<97 || s[i]>122)
            {
                while(!op.empty() && prec(s[i]) < prec(op.top()))
                {
                    out+=op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else out+=s[i];
        }
        while(!op.empty())out+=op.top(), op.pop();
        cout<<out<<"\n";
    }
    return 0;
}