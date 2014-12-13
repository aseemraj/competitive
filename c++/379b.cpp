#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int a[1000];
int main()
{
    int n;
    cin>>n;
    loop(i, 0, n)
        cin>>a[i+1];
    loop(i, 1, n)
    {
        loop(j, 0, a[i])
            cout<<"PRL";
        cout<<"R";
    }
    loop(i, 0, a[n])
        cout<<"PLR";
    cout<<endl;
    return 0;
}
