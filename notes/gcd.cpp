#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
typedef long long ll;
using namespace std;
ll gcd(ll a, ll b){ll c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
unsigned int binarygcd(unsigned int u, unsigned int v)
{
    if(u==0)return v;if(v==0)return u;
    int shift;
    for(shift=0;((u|v)&1)==0;++shift){u>>=1;v>>=1;}
    while((u&1)==0)u>>=1;
    do{while((v&1)==0)v>>=1;if(u>v){unsigned int t = v; v = u; u = t;}v=v-u;}while (v!=0);
    return u<<shift;
}
