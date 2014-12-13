#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2,temp;
    int t,count,j;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        count=0,j=0;
        if(s1.size()>s2.size())
        {
            temp=s2;
            for(int i=0;i<s1.size();i++)
            {
                if(s1[i]==s2[j])
                {
                    count++;
                    j++;
                }
            }
        }
        else
        {
            temp=s1;
            for(int i=0;i<s2.size();i++)
            {
                if(s2[i]==s1[j])
                {
                    count++;
                    j++;
                }
            }
        }
        if(count==temp.size())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
