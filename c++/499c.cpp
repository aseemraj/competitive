#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    ll hx, hy, ux, uy, a, b, c, cnt, d1, d2; int n;
    cin>>hx>>hy>>ux>>uy;
    cin>>n;
    cnt = 0;
    loop(i, 0, n)
    {
        cin>>a>>b>>c;
        d1 = a*hx + b*hy + c;
        d2 = a*ux + b*uy + c;
        if((d1<0&&d2>0)||(d1>0&&d2<0))cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
