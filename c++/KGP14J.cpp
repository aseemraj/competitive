#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int digitsin(int x){int c=0;while(x){x/=10;c++;}return c;}
int main()
{
    ios_base::sync_with_stdio(0);
    ll t, x, y, k, dig;
    double p, m, n;
    cin>>t;
    loop(i, 1, t+1)
    {
        cin>>x>>y;
        cout<<"Case "<<i<<": ";
        k = digitsin(y);
        loop(e, 1, 1005)
        {
            p = e*log10(1.0*x);
            dig = pow(10.0, p - int(p+1) + k);
            if(dig==y){cout<<e<<endl;break;}
        }
    }
    return 0;
}
