#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    ll a, b, num, sr;
    cin>>a>>b;
    if(a<b){cout<<0<<endl;return 0;}
    else if(a==b){cout<<"infinity\n";return 0;}
    num = a-b;
    sr = sqrt(1.0*num);
    int c = 0;
    loop(i, 1, sr+1)
    {
        if(num%i==0)
        {
            if(a%i==b)c++;
            if(a%(num/i)==b && i!=(num/i))c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
