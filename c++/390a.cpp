#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    bool row[101]={false};
    bool col[101]={false};
    int n, cr=0, cc=0, x, y;
    cin>>n;
    loop(i, 0, n)
    {
        cin>>x>>y;
        row[x] = true;
        col[y] = true;
    }
    loop(i, 0, 101)
    {
        if(row[i])
            cr++;
        if(col[i])
            cc++;
    }
    cout<<min(cr, cc)<<endl;
    return 0;
}
