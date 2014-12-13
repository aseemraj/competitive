#include<iostream>
using namespace std;
int main()
{
    int n, i, p;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        int a[n+1], b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[a[i]-1] = i+1;
        }
        p = 0;
        for(i=0;i<n;i++)
        {
            if(b[i]!=a[i])
            {
                p = 1;
                break;
            }
        }
        if(p==1)
            cout<<"not ambiguous\n";
        else
            cout<<"ambiguous\n";
    }
}
