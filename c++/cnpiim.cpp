#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<=b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t, n, a, val, nr;
    unsigned ll s, k, lim;
    cin>>t;
    while(t--)
    {
        s = 0;
        cin>>n;
        lim = n/2;
        loop(i, 1, lim)
        {
            k = i*(n-i);
            nr = (int)sqrt(k-1);
            for(int j=1;j<=nr;j++)
            {
                if(k%j==0)
                    val = (k)/j-1;
                else
                    val = k/j;
                s += (val-j)*2+1;
                if(i!=(n-i))
                    s += (val-j)*2+1;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
