#include<iostream>
using namespace std;
int main()
{
    int t, n, i;
    string m, f, ct;
    cin>>t;
    while(t--)
    {
        ct = "";
        cin>>m>>f;
        cin>>n;
        string c[n];
        for(i=0;i<n;i++)
        {
            cin>>c[i];
            ct = ct + c[i];
        }
    }
    return 0;
}
