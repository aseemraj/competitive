#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n];
    loop(i, 0, n)cin>>a[i];
    int mn = INT_MAX, mx;
    loop(i, 1, n-1)
    {
        vector<int> v;
        loop(j, 0, n)if(j!=i)v.push_back(a[j]);
        mx = 0;
        loop(j, 1, n-1)
            mx = max(mx, v[j]-v[j-1]);
        mn = min(mn, mx);
    }
    cout<<mn<<endl;
    return 0;
}
