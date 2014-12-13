#include<iostream>
#include<string>
using namespace std;
int main()
{
   int t,n,i,j,tmp;
   string c,p,s,x,y;
   cin>>t;
   while(t--)
   {
       int flag=1,flag1=1,flag2=1;
       int temp=-1,temp1=-1;
       cin>>n;
       for(i=0;i<n;i++)
       {
           cin>>c[i]>>p[i];
       }
       cin>>s;
      // cout<<s.length()<<"\n";
       for(i=0;i<s.length();i++)
       {
           for(j=0;j<n;j++)
           {
               if(s[i]==c[j])
                   {
                       s[i]=p[j];
                       break;
                   }
           }
       }
       i=0;
       while(s[i]=='0')
       {
           temp++;
           i++;
       }
       for(i=0;i<s.length();i++)
       {
           if(s[i]=='.')
               {
                   flag=0;
                   tmp=i;
                   break;
               }
       }
       if(flag== 0)
       {
           x=s.substr(tmp+1,s.length());
           y=s.substr(0,tmp+1);
           for(i=0;i<x.length();i++)
           {
               if(x[i]!='0')
               {
                   flag1=0;
                   break;
               }
           }
           for(i=0;i<y.length()-1;i++)
           {
               if(y[i]!='0')
               {
                   flag2=0;
                   break;
               }
           }
      // cout<<"\n"<<flag1<<"\t"<<flag2<<"\n";
           if(flag1!=0 && flag2!=0)
           {
               cout<<"0";
           }
           else if(flag1==0)
           {
               int len = x.length() - 1;
               for(i=0;i<(x.length())/2;i++)
               {
                   char te = x[i];
                   x[i]=x[len];
                   x[len--]=te;
               }
                   i=0;
               while(x[i]=='0')
               {
                   temp1++;
                   i++;
               }
               x=x.substr(temp1+1,x.length());
               int le=x.length()-1;
               for(i=0;i<(x.length())/2;i++)
               {
                   char tee = x[i];
                   x[i]=x[le];
                   x[le--]=tee;
               }
               for(i=temp+1;i<y.length();i++)
                   cout<<y[i];
               for(i=0;i<x.length();i++)
                   cout<<x[i];
           }
           else
               for(i=temp+1;i<y.length()-1;i++)
                   cout<<y[i];
               cout<<"\n";
       }
       else
       {
           if(s.length()== 1)
               {
                   cout<<s;
                   cout<<"\n";
               }
           else
           {
               for(i=temp+1;i<s.length();i++)
                   cout<<s[i];
               cout<<"\n";
           }
       }
   }
   return 0;
}
