#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    ll r, g, b;
    cin>>r>>g>>b;
    cout<<min((r+g+b)/3, (r+g+b) - max(r, max(g, b)));
    return 0;
}
