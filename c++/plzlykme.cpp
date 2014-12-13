#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    unsigned ll l, d, s, c;
    cin>>t;
    while(t--)
    {
        cin>>l>>d>>s>>c;
        loop(i, 1, d)
        {
            s += c*s;
            if(s>=l)
                break;
        }
        if(s>=l)
            cout<<"ALIVE AND KICKING\n";
        else
            cout<<"DEAD AND ROTTING\n";
    }
    return 0;
}
