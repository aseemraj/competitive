#include<iostream>
using namespace std;

int main()
{
    int y[501][501];
    int b[501][501];
    int a[501][501];

    int i,j,n,m,q,g;
    cin>>n>>m;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>y[i][j];
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>b[i][j];
        }
    }
    cin>>q>>g;

    return 0;
}
