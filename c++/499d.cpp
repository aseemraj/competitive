#include <bits/stdc++.h>
#define eps 1e-9
#define bs 1000000009
#define bsize 256
using namespace std;
long n,T;
double p[1<<15];
long t[1<<15];
double temp,pl[1<<15];
double prob[5050][5050];
double ans;
double plast,pmove;
double rem[4][100000];

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>T;

for (int i=1;i<=n;i++)
{
 cin>>p[i]>>t[i];
 p[i]*=0.01;
 temp=1;
 for (int j=1;j<t[i];j++)
 {
  temp*=(1.0-p[i]);
 }
 pl[i]=temp;
}

prob[1][1]=1;

for (int i=1;i<=T;i++)
{
 for (int j=0;j<=n;j++)
  rem[(i+1)%2][j]=0;

 for (int cur=1;cur<=n;cur++)
 {
     if (i<t[cur])plast=0;
     else
     {
      plast=prob[i-t[cur]+1][cur]*pl[cur];
     }
     pmove=plast*1+(prob[i][cur]-plast)*p[cur];
     prob[i+1][cur+1]+=pmove;
     ans+=pmove;

    // cout<<i<<"   "<<cur<<" "<<pmove<<endl;
     prob[i+1][cur]+=prob[i][cur]-pmove;
     rem[(i+1)%2][cur]+=prob[i][cur]-pmove;
 }/*
 cout<<T<<":"<<endl;
 for (int cur=1;cur<=n;cur++)
 {
     cout<<rem[i%2][cur]<<" ";
     cout<<endl;
 }*/

 for (int cur=1;cur<=n;cur++)
  prob[i][cur]-=rem[i%2][cur];

}
/*
for (int i=0;i<=T+1;i++)
{
    for (int j=0;j<=n+1;j++)
    {
     cout<<prob[i][j]<<" ";
    }
    cout<<endl;
}*/

cout.precision(12);
/*
for (int i=T+1;i<=T+1;i++)
 for (int j=1;j<=n+1;j++)
  ans+=prob[i][j]*(j-1);
*/
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}
