#include <bits/stdc++.h>
using namespace std;

int main()
{   int t;
    cin>>t;
    while(t--)
    {
    string s;
    cin>>s;
    unsigned long long i,len,a=0,b=0,v,z=0;
    len=s.length();
    for(i=0;i<len;i++)
    {
        if(s[i]=='<')
        {
            a++;
        }
        if(s[i]=='>')
        {
            b++;
        }
        if(b>a)
        {
            break;
        }
    }
    if(i==len)
    {
        if(a==b)
        {
         cout<<b+b<<endl;
        }
        else if(a>b)
        {
         for(i=0;i<len;i++)
         {
             if(s[i]=='>')
             {
                 v=i;
             }
         }

         for(i=0;i<v;i++)
         {
             if(s[i]=='<')
             {
                 z++;
             }
         }
         if(z==b)
         {
             cout<<b+b<<endl;
         }
         else
        {
            cout<<'0'<<endl;
        }
        }
        else
        {
            cout<<'0'<<endl;
        }
    }
    else
    {
       if(a==b-1)
        {
         cout<<b+b-2<<endl;
        }
        else
        {
            cout<<'0'<<endl;
        }
    }
    }
    return 0;
}
