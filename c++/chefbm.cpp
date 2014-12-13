#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=b-1;i>=a;i--)
using namespace std;
typedef long long LL;
//LL power(LL a, LL p, LL mod){LL ret = 1;while(p){if(p&1)ret=(ret*a)%mod;a=(a*a)%mod;p/=2;}return ret;}
pair<int, int> P[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,p;
    cin>>n>>m>>p;
    loop(i, 0, p)
        cin>>P[i].first>>P[i].second;
    sort(P,P+p);
    int j=0;
    loop(i, 1, n+1)
    {
        map<int,int> check;
        int A[2];
        A[0]=1; A[1]=m;
        if(m!=1)
            while(j<p && P[j].first==i)
            {
                check[P[j].second]++;
                if(P[j].second<m)
                    check[P[j].second + 1]--;
                if(P[j].second==1)
                    A[0]++;
                else if(P[j].second==m)
                    A[1]++;
                j++;
            }
        bool flag=true;
        for(map<int, int>::const_iterator i=check.begin();i!=check.end();i++)
        {
            if(i->second < -1)
            {
                flag=false;
                break;
            }
        }
        if(!flag)
            cout<<"-1\n";
        else
            cout<<A[1]-A[0]<<endl;
    }
    return 0;
}
