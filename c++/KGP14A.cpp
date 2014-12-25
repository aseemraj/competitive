#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, k, c;
    cin>>t;
    loop(i, 1, t+1)
    {
        cin>>k;
        int kid[k], pen[k];
        loop(j, 0, k)cin>>kid[j];
        loop(j, 0, k)cin>>pen[j];
        sort(kid, kid+k);sort(pen, pen+k);
        c = 0;
        loop(j, 0, k)c+=abs(kid[j]-pen[j]);
        cout<<"Case "<<i<<": "<<c<<endl;
    }
    return 0;
}
