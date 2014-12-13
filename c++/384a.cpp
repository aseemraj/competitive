#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<(n+1)*(n+1)/4 + (n/2)*(n/2)<<endl;
        loop(i, 1, n+1)
        {
            if(i&1)
            {
                loop(j, 0, n/2)
                    cout<<"C.";
                cout<<"C\n";
            }
            else
            {
                loop(j, 0, n/2)
                    cout<<".C";
                cout<<".\n";
            }
        }
    }
    else
    {
        cout<<n*n/2<<endl;
        loop(i, 1, n+1)
        {
            if(i&1)
            {
                loop(j, 0, n/2)
                    cout<<"C.";
                cout<<"\n";
            }
            else
            {
                loop(j, 0, n/2)
                    cout<<".C";
                cout<<"\n";
            }
        }
    }
    return 0;
}
