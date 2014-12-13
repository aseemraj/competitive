#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int c[1000002];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, q, x;
    cin>>n;
    loop(i, 0, n)
    {
        cin>>x;
        c[x]++;
    }
    cin>>q;
    while(q--)
    {
        cin>>x;
        cout<<c[x]<<endl;
    }
    return 0;
}
