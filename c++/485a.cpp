#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int gcd(ll a, ll b){if(b == 0)return a;else return gcd(b, a % b);}
int main()
{
    ios_base::sync_with_stdio(0);
    ll a, m;
    cin>>a>>m;
    bool ans = 0;
    loop(i, 0, m+1)
    {
        a += a%m;
        if(a%m==0)
        {
            ans = 1;
            break;
        }
    }
    if(ans)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
