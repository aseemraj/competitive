#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin>>n>>m;
    int w[n+1], b[m];
    loop(i, 1, n+1)cin>>w[i];
    loop(i, 0, m)cin>>b[i];

    ll wt = 0;
    loop(i, 1, m)
    {
        bool mark[505] = {0};
        for(int j=i-1;j>=0 && b[j]!=b[i];j--)
        {
            if(!mark[b[j]])
            {
                mark[b[j]] = 1;
                wt += w[b[j]];
            }
        }
    }
    cout<<wt<<endl;
    return 0;
}
