#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    cin>>n;
    if(n==0)cout<<1<<endl;
    else if(n&1)cout<<4+(n/2)*12<<endl;
    else cout<<((n-1)/2)*12+8<<endl;
    return 0;
}
