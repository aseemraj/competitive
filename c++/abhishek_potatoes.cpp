#include <bits/stdc++.h>
using namespace std;
unsigned long long arr1[32], arr2[32];

int main()
{

    unsigned long long n,a,b;
    cin>>n;
    while(n--)
    { int i=0,j=0, k=0;
      cin>>a;
      cin>>b;
    while(a>0)
    {   arr1[i]=a;
        i++;
        a=a/2;
    }
    while(b>0)
    {
        arr2[j]=b;
        j++;
        b=b/2;
    }
for(i=0;i<32;i++)
{
    for(j=0;j<32;j++)
    {
        if(arr1[i]==arr2[j])
        {
            k=1;
            break;
        }
    }
    if(k==1)
    {
        break;
    }
}
cout<<i+j<<endl;
    }
return 0;
}
