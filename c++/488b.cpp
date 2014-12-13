#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define MX 1000000
typedef long long ll;
using namespace std;
bool inrange(int a, int b)
{
    if(a>0 && b>0 && a<=MX && b<=MX)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, x, y, a, b;
    cin>>n;
    int s[4];
    loop(i, 0, n)cin>>s[i];
    if(n==0)cout<<"YES\n1\n2\n2\n3\n";
    else if(n==1)cout<<"YES\n"<<2*s[0]<<"\n"<<2*s[0]<<"\n"<<3*s[0]<<"\n";
    else if(n==2)
    {
        y = max(s[0], s[1]);
        x = min(s[0], s[1]);
        a = 4*x - y;
        b = 3*x;
        if(inrange(a, b)){cout<<"YES\n"<<a<<endl<<b<<endl;return 0;}
        if(y==3*x){cout<<"YES\n"<<2*x<<endl<<2*x<<endl;return 0;}
        if((x+y)%4==0){cout<<"YES\n"<<(y+x)/4<<endl<<3*(y+x)/4<<endl;return 0;}
        if(y%3==0)a=y/3;
        b = 4*a-x;
        if(inrange(a, b)){cout<<"YES\n"<<a<<endl<<b<<endl;return 0;}
        cout<<"NO\n";
    }
    else if(n==3)
    {
        sort(s, s+3);
        if(s[2]%3==0 && (s[0]+s[1])%2==0 && (4*s[2]/3)==s[0]+s[1])cout<<"YES\n"<<s[2]/3<<endl;
        else if(s[2]==3*s[0] && 4*s[0]-s[1]>0)cout<<"YES\n"<<4*s[0]-s[1]<<endl;
        else if((s[1]+s[2])%2==0 && s[1]+s[2]==4*s[0])cout<<"YES\n"<<3*s[0]<<endl;
        else cout<<"NO\n";
    }
    else
    {
        sort(s, s+4);
        if((s[1]+s[2])%2==0 && s[3]-s[0]==(s[1]+s[2])/2 && (s[0]+s[1]+s[2]+s[3])/4==s[3]-s[0] && (s[0]+s[1]+s[2]+s[3])%4==0)
            cout<<"YES\n";
        else cout<<"NO";
    }
    return 0;
}
