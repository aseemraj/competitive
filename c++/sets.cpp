#include<iostream>
using namespace std;
int a[1000001];
int main()
{
    int i;
    int n, t, y, counter,x;
    cin>>t;
    while(t--)
    {
        counter = 0;
        for(i=0; i<1000001; i++)
            a[i] = 0;

        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x;
            a[x]++;
        }

        for(i=0;i<1000001/2;i++)
        {
            if(a[i]>0)
            {
                y = min(a[2*i], a[i]);
                counter += y;
                a[i] -= y;
                a[2*i] -= y;

            }
        }

        cout<<counter<<endl;
    }
    return 0;
}
