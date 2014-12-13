#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, mx = 0, cmx = 0, a;
    cin>>n;
    loop(i, 0, n)
    {
        cin>>a;
        if(a!=0)
            cmx++;
        else
        {
            mx = max(mx, cmx);
            cmx = 0;
        }
    }
    mx = max(cmx, mx);
    cout<<mx<<endl;
    return 0;
}
