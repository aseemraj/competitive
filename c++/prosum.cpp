#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t, a;
    ll n, tc, tot;
    cin>>t;
    while(t--)
    {
        cin>>n;
        tot = n;
        tc = 0;
        loop(i, 0, n)
        {
            cin>>a;
            if(a<=1)
                tot--;
            else if(a==2)
                tc++;
        }
        tot = (tot*(tot-1))/2;
        tot -= (tc*(tc-1))/2;
        cout<<tot<<endl;
    }
    return 0;
}
