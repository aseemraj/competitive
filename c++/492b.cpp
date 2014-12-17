#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, l;
    cin>>n>>l;
    double a[n];
    loop(i, 0, n)cin>>a[i];
    double k = 0, mn = 0;
    sort(a, a+n);
    loop(i, 0, n-1)
    {
        mn = max(mn, a[i]-k);
        k = (a[i+1]+a[i])/2.0;
    }
    mn = max(mn, a[n-1]-k);
    mn = max(mn, l - a[n-1]);
    cout<<fixed<<setprecision(9)<<mn<<endl;
    return 0;
}
