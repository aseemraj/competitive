#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=b-1;i>=a;i--)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long n, k, mx, mn;
    cin>>n>>k;
    long long a[n];
    mn = 1000000001<<1;
    mx = -1*(1000000001<<1);
    loop(i, 0, n)
    {
        cin>>a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(k!=0)
    {
        if(k&1)
        {
            loop(i, 0, n)
                a[i] = mx - a[i];
        }
        else
        {
            loop(i, 0, n)
                a[i] = a[i] - mn;
        }
    }
    cout<<a[0];
    loop(i, 1, n)
        cout<<' '<<a[i];
    cout<<endl;
	return 0;
}
