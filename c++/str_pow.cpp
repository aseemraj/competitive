#include<iostream>
#include<string>
using namespace std;
long long gcd(long long ,long long);
int main()
{
    int t;
    string s1, s2;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        string s=s1,m=s2;
        long long num1=s1.size();
        long long num2=s2.size();

       // cout<<lcm;
        long long i, j;
        i = min(num1, num2);
        j = max(num1, num2);
        int temp=0;
        if(num1>num2){
            string sss=s1.substr(0,num2);
            if(sss==s2)
                temp=1;
        }
        else {
                string sss=s2.substr(0,num1);
            if(sss==s1)
                temp=1;
        }

        if(temp==1){
            while(i<j && temp==1)
            {
                long long lcm=(gcd(num1,num2));
    //cout<<lcm;
                if(num1<num2)
                {
                    s2 = s2.substr(lcm);
                    num2 = s2.size();
                }
                else
                {
                    s1 = s1.substr(lcm);
                    num1 = s1.size();
                }
                i = min(num1, num2);
                j = max(num1, num2);
                if(num1>num2){
                string sss=s1.substr(0,num2);
                if(sss==s2)
                    temp=1;
                  else temp=0;
                }
                else {
                        string sss=s2.substr(0,num1);
                    if(sss==s1)
                        temp=1;
                     else temp=0;
                }
            }
        }
        if(s1==s2 && temp==1){
            cout<<"YES"<<endl;
        }
        else    cout<<"NO"<<endl;

    }
    return 0;
}
long long gcd(long long a,long long b)
{
long long r;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;}


