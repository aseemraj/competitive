#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, sum, c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int b[n];
        sum=0, c=0;
        loop(i, 0, n)
        {
            cin>>b[i];
            sum+=b[i];
            if(b[i]>0)c++;
        }
        k = sum-100;
        if(k<0)cout<<"NO\n";
        else if(k<c)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
