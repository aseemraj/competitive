#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n, x, t = 0;
    cin>>n>>x;
    int c[n];
    loop(i, 0, n)
        cin>>c[i];
    sort(c, c+n);
    loop(i, 0, n)
    {
        if(x>1)
        {
            t += x*c[i];
            x--;
        }
        else
            t += c[i];
    }
    cout<<t<<endl;
    return 0;
}
