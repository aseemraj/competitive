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
    int t, n, mx, temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int w[n];
        loop(i, 0, n)
            cin>>w[i];
        temp = w[n-1];
        rloop(i, 0, n)
        {
            if(temp<w[i])
                temp = w[i];
            temp++;
        }
        temp--;
        cout<<temp<<endl;
    }
    return 0;
}
