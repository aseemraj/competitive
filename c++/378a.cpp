#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int a, b;
    int mina, minb, wina=0, winb=0, draw=0;
    cin>>a>>b;
    loop(i, 1, 7)
    {
        mina = abs(i-a);
        minb = abs(i-b);
        if(mina>minb)
            winb++;
        else if(mina<minb)
            wina++;
        else
            draw++;
    }
    cout<<wina<<' '<<draw<<' '<<winb<<endl;
    return 0;
}
