#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
string f;
bool good(int i, int n)
{
    return ((f[i]=='1'&&f[i+1]=='0'&&f[i+2]=='1')||(f[i]=='0'&&f[i+1]=='1'&&f[i+2]=='0')||(f[n-i-1]=='0'&&f[n-i-2]=='1'&&f[n-i-3]=='0')||(f[n-i-1]=='1'&&f[n-i-2]=='0'&&f[n-i-3]=='1'))?true:false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, m;
    bool g;
    cin>>t;
    while(t--)
    {
        g = false;
        cin>>f;
        n = f.length();
        m = n-1>>1;
        loop(i, 0, m)
        {
            if(good(i, n))
            {
                g = true;
                break;
            }
        }
        if(g)
            cout<<"Good\n";
        else
            cout<<"Bad\n";
    }
    return 0;
}
