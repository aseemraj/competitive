#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n], b[n], p1[n], p2[n];
    memset(p1, 0, sizeof p1);
    memset(p2, 0, sizeof p2);
    loop(i, 0, n)
        cin>>a[i]>>b[i];
    int c[n<<1];
    int p = 0, q = 0;
    loop(k, 0, n/2)
    {
        p1[k] = 1;
        p2[k] = 1;
    }
    p = 0, q = 0;
    loop(j, 0, n)
    {
        if(a[p]<b[q])
        {
            p1[p] = 1;
            p++;
        }
        else
        {
            p2[q] = 1;
            q++;
        }
    }
    loop(i, 0, n)
        cout<<p1[i];
    cout<<endl;
    loop(i, 0, n)
        cout<<p2[i];
    cout<<endl;
    return 0;
}
