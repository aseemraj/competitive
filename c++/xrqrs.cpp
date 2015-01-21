/*
Author: Aseem Raj Baranwal
Problem: XOR Queries
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;
int a[500005];
int main()
{
    ios_base::sync_with_stdio(0);
    int m, x, l, r, k, sz, c, y;
    sz = 0;
    cin>>m;
    while(m--)
    {
        cin>>c;
        if(c==0)
        {
            cin>>x;
            a[sz++] = x;
        }
        else if(c==1)
        {
            cin>>l>>r>>x;
            k = a[l-1]^x, y = a[l-1];
            loop(i, l, r)if((a[i]^x)>k)k=a[i]^x,y=a[i];
            cout<<y<<endl;
        }
        else if(c==2)
        {
            cin>>k;
            sz -= k;
        }
        else if(c==3)
        {
            cin>>l>>r>>x;
            y = 0;
            loop(i, l-1, r)if(a[i]<=x)y++;
            cout<<y<<endl;
        }
        else if(c==4)
        {
            cin>>l>>r>>k;
            int b[r-l+1];
            y = 0;
            loop(i, l-1, r)b[y++]=a[i];
            sort(b, b+r-l+1);
            cout<<b[k-1]<<endl;
        }
    }
    return 0;
}
