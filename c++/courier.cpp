#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define INF 1<<28
typedef long long ll;
using namespace std;
ll B, dist[101][101], memo[101][1<<15];
vector< pair <int, int> > vec;
void floydwarshall(int n){loop(k, 1, n+1)loop(i, 1, n+1)loop(j, 1, n+1)dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j]);}
ll solvedp(int b, int mask)
{
    if(memo[b][mask]!=-1)       // saving computation by memoization
        return memo[b][mask];
	ll ans = INF;
	bool f = 0;
	for(int i=0;i<vec.size();i++)
        if(!(mask & (1<<i)))    // ith order is not completed
        {
            f = 1;
            ans = min(ans, dist[b][vec[i].first] + dist[vec[i].first][vec[i].second] + solvedp(vec[i].second, mask | (1<<i)));
        }
	if(!f)return memo[b][mask] = dist[b][B];
	return memo[b][mask] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m, b, u, v, d, z;
    cin>>t;
    while(t--)
    {
        vec.clear();
        memset(memo, -1, sizeof memo);
        cin>>n>>m>>B;
        loop(i, 1, n+1)loop(j, 1, n+1){dist[i][j]=INF;if(i==j)dist[i][j]=0;}
        while(m--)
        {
            cin>>u>>v>>d;
            dist[u][v] = dist[u][v]<d?dist[u][v]:d;
            dist[v][u] = dist[v][u]<d?dist[v][u]:d;
        }
        cin>>z;
        while(z--)
        {
            cin>>u>>v>>b;
            while(b--)vec.push_back(make_pair(u, v));
        }
        floydwarshall(n);
        cout<<solvedp(B, 0)<<endl;
    }
    return 0;
}
