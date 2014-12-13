#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int a, b, c, d, t;
    string p, q, r, s;
    char ans;
    vector<int> v;
    cin>>p>>q>>r>>s;
    a = p.size()-2;
    b = q.size()-2;
    c = r.size()-2;
    d = s.size()-2;
    t = a<<1;
    if((t<=b&&t<=c&&t<=d)||(a>=2*b&&a>=2*c&&a>=2*d))
        v.push_back(1);
    t = b<<1;
    if((t<=a&&t<=c&&t<=d)||(b>=2*a&&b>=2*c&&b>=2*d))
        v.push_back(2);
    t = c<<1;
    if((t<=b&&t<=a&&t<=d)||(c>=2*b&&c>=2*a&&c>=2*d))
        v.push_back(3);
    t = d<<1;
    if((t<=b&&t<=c&&t<=a)||(d>=2*b&&d>=2*c&&d>=2*a))
        v.push_back(4);
    if(v.size()==1)
        ans = char(64+v[0]);
    else
        ans = 'C';
    cout<<ans<<endl;
    return 0;
}
