#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int n = s.length(), k;
    int a = 0, b = 0, c = 0, i = 0;
    while(s[i]!='+')a++,i++;i++;
    while(s[i]!='=')b++,i++;i++;
    while(i<n)c++,i++;
    if(a+b==c)cout<<s;
    else if(abs(a+b-c)!=2)cout<<"Impossible\n";
    else
    {
        if(c>a+b)c-=1,a+=1;
        else c+=1,a-=1;
        if(a==0)a++,b--;
        while(a--)cout<<'|';cout<<'+';
        while(b--)cout<<'|';cout<<'=';
        while(c--)cout<<'|';cout<<endl;
    }
    return 0;
}
