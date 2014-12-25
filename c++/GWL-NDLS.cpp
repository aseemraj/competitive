#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int w=20,h=20,c;string brick="___",s="",gap="";int wid=w*4+4;
    loop(i, 0, wid/2-4)s+=' ';
    loop(i, 0, wid/10)
    {
        if(i==wid/10-1&&wid>=40)cout<<s<<"___/"<<gap.substr(0, gap.length()/2-5)<<"OUR  HOUSE"<<gap.substr(0, gap.length()/2-5)<<"\\___"<<endl;
        else{cout<<s<<"___/"<<gap<<"\\___"<<endl;s=s.substr(0, s.length()-5);gap+="          ";}
    }
    loop(i, 0, wid)cout<<'.';cout<<endl;
    loop(j, 0, h)
    {
        c = 0;
        if(j%3==1){cout<<"|__";c=1;}
        else if(j%3==2){cout<<"|_";c=2;}
        loop(i, 0, w)cout<<'|'<<brick;
        if(c==0)cout<<"|__|"<<endl;
        else if(c==1)cout<<"|"<<endl;
        else if(c==2)cout<<"_|"<<endl;
    }
    return 0;
}
