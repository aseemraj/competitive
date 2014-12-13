#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int xormax(int* a, int n, int k)
{
    set<int> s;
    s.insert(0);
    loop(i, 0, n)
        for(set<int>::iterator j=s.begin();j!=s.end();j++)
            if(s.find(a[i]^(*j))==s.end())s.insert(a[i]^(*j));
    int mxor = k;
    for(set<int>::iterator j=s.begin();j!=s.end();j++)
        mxor = max(mxor, k^(*j));
    return mxor;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        loop(i, 0, n)cin>>a[i];
        sort(a, a+n, greater<int>());
        cout<<xormax(a, n, k)<<endl;
    }
    return 0;
}
