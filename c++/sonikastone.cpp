#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        int k = 0;
        int countt = 0;
        int sum =0;
        int m=0;
        for(int i=0; i<a.length(); i++)
        {
           if(a[i] == '<')
           {
               sum++;
           }
           if(a[i] == '>')
           {
               sum--;
           }
           if(sum == 0 )
           {
             m++;
           }
           if(sum<0)
           {
               sum = 0;
               break;
           }
           countt++;
        }
        if(m !=0)
        {
            k = 1;
            cout<<countt-sum<<endl;
        }
        if(k==0)
        {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
