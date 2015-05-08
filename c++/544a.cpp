/*
Author: aseemraj
Problem: 544A
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
    int k, c = 0;
    string q;
    cin>>k>>q;
    int sz = q.size();
    bool check[200] = {0};
    V(char) v;
    loop(i, 0, sz)
    {
        if(!check[q[i]])
        {
            c++, check[q[i]] = 1;
            if(c<=k)v.PB(q[i]);
        }
    }
    if(c<k)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        int j = 0, l = 1;
        while(l<v.size())
        {
            while(q[j]!=v[l])
            {
                cout<<q[j];
                j++;
            }
            cout<<"\n";
            l++;
        }
        if(j<sz)
        {
            while(j<sz)
                cout<<q[j++];
            cout<<"\n";
        }
    }
    return 0;
}
