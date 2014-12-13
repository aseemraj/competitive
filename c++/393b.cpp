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
    double w[n][n];
    double wt[n][n];
    double a[n][n];
    double b[n][n];
    loop(i, 0, n)
    {
        loop(j, 0, n)
        {
            cin>>w[i][j];
            wt[j][i]=w[i][j];
        }
    }
    loop(i, 0, n)
    {
        loop(j, 0, n)
        {
            a[i][j] = 0.5*(w[i][j]+wt[i][j]);
            b[i][j] = 0.5*(w[i][j]-wt[i][j]);
        }
    }
    loop(i, 0, n)
    {
        cout<<a[i][0];
        loop(j, 1, n)
        {
            cout<<' '<<a[i][j];
        }
        cout<<endl;
    }
    loop(i, 0, n)
    {
        cout<<b[i][0];
        loop(j, 1, n)
        {
            cout<<' '<<b[i][j];
        }
        cout<<endl;
    }
    return 0;
}
