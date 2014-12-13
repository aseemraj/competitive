#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, c, x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool p[100005] = {0};
        c = 0;
        while(n--)
        {
            cin>>x;
            if(!p[x])
            {
                p[x] = 1;
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
