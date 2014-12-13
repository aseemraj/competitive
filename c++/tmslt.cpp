#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
#define MILL 1000000
using namespace std;
int s[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, a, b, c, d;
    int diff;
    ll temp;
    bool player;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>c>>d;
        memset(s, 0, sizeof s);
        s[d]++;
        temp = d;
        loop(i, 1, n)
        {
            temp = (a*temp*temp + b*temp + c)%MILL;
            s[temp]++;
        }
        diff = 0;
        player = true;
        for(int i=999999;i>0;i--)
        {
            if(s[i]>0)
            {
                if(player && s[i]%2==1)
                {
                    diff += i;
                    player = false;
                }
                else if(!player && s[i]%2==1)
                {
                    diff -= i;
                    player = true;
                }
            }
        }
        cout<<abs(diff)<<endl;
    }
    return 0;
}
