#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define maxpn 1000000005
#define rootn 31635
typedef long long ll;
using namespace std;
ll a[105], xp[105], yp[105], n;
ll f[rootn], primecount=0;
ll factor[100][rootn];
vector<ll> prime;
void sieve()
{
    loop(i, 2, rootn)
        if(f[i]==0)
        {
            prime.pb(i);
            for(int j=2*i;j<rootn;j+=i)
            f[j]=1;
        }
}

void factorize()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=0;j<prime.size();j++)
            while(a[i]%prime[j]==0)
            {
                factor[i][j]++;
                a[i]/=prime[j];
            }
}

int main()
{
    prime.clear();
    sieve();
    int m;
    cin>>n>>m;
    ll ans=0;
    loop(i, 1, n+1)cin>>a[i];
    factorize();
    loop(i, 0, m)
    {
        cin>>xp[i]>>yp[i];
        loop(j, 0, rootn)
        if(factor[xp[i]][j]>0 && factor[yp[i]][j] >0)
        {
            ans+=min(factor[xp[i]][j],factor[yp[i]][j]);
            if( factor[xp[i]][j] < factor[yp[i]][j] )
            {
                factor[yp[i]][j]-=factor[xp[i]][j];
                factor[xp[i]][j]=0;
            }
            else
            {
                factor[xp[i]][j]-=factor[yp[i]][j];
                factor[yp[i]][j]=0;
            }
        }
    }
    loop(i, 0, m)
    {
        if(a[xp[i]]>1 && a[yp[i]]>1 )
        {
            if(a[xp[i]]==a[yp[i]])
                ans+=1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
