#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int axbmodc(int a,int b,int c)
{
    return a?(axbmodc(c%a, (a-b % a)%a, a)*c + b)/a:0;
}
int main()
{
    int a, b, c;
    while(1){
    cout<<"Enter a b c: ";
    cin>>a>>b>>c;
    cout<<"Solution for ax=b (mod c): "<<axbmodc(a, b, c)<<endl;
    }
    return 0;
}
