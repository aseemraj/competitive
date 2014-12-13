#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int a[100002];
ll b[100002];
int main()
{
    int n, k;
    ll joy=0;
    cin>>n;
    loop(i, 0, n)
        cin>>a[i];
    loop(i, 0, n)
        cin>>b[i];
    loop(i, 0, n)
    {
        if(b[i]==1)
            joy--;
        else if(b[i]%2==0 && b[i]/2 <=a[i])
        {
            joy += (b[i]/2)*(b[i]/2);
        }
        else if(b[i]%2!=0 && b[i]/2 <=a[i] && (b[i]/2)+1<=a[i])
        {
            joy += (b[i]/2)*((b[i]/2)+1);
        }
        else
            joy--;
    }
    cout<<joy<<endl;
    return 0;
}
