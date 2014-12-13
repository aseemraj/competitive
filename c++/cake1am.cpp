#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int cake[1002][1002];
int main()
{
    int t, x1, x2, y1, y2, area;
    cin>>t;
    while(t--)
    {
        loop(i, 0, 1002)
            loop(j, 0, 1002)
                cake[i][j] = 1;
        area = 0;
        cin>>x1>>y1>>x2>>y2;
        area += (x2-x1)*(y2-y1);
        loop(i, x1, x2)
            loop(j, y1, y2)
                cake[i][j] = 0;
        cin>>x1>>y1>>x2>>y2;
        loop(i, x1, x2)
            loop(j, y1, y2)
                if(cake[i][j]==1)
                    area++;
        cout<<area<<endl;
    }
    return 0;

}
