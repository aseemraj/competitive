/*
Author: aseemraj
Problem: 547B
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int parent[200005], rankof[200005], sz[200005], result[200005];
bool visited[200005];
void initialize()
{
    int i;
    loop(i, 0, 200005)
    {
        parent[i] = i;
        rankof[i] = 1;
        sz[i] = 1;
    }
}
int Find(int nd)
{
    if(parent[nd] != nd)
        parent[nd] = Find(parent[nd]);
    return parent[nd];
}
void Union(int nd1, int nd2, int val)
{
    int x = Find(nd1);
    int y = Find(nd2);
    if(rankof[x] > rankof[y])
    {
        parent[y] = x;
        sz[x] += sz[y];
        result[sz[x]] = max(result[sz[x]], val);
    }
    else if(rankof[x] < rankof[y])
    {
        parent[x] = y;
        sz[y] += sz[x];
        result[sz[y]] = max(result[sz[y]], val);
    }
    else
    {
        parent[y] = parent[x];
        sz[x] += sz[y];
        result[sz[x]] = max(result[sz[x]], val);
        rankof[x]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    memset(visited, false, sizeof(visited));
    initialize();
    int n, i, tmp;
    cin>>n;
    VP v;
    loop(i, 1, n+1)
    {
        cin>>tmp;
        result[1] = max(result[1], tmp);
        v.push_back(make_pair(tmp, i));
    }
    sort(v.begin(), v.end());
    rloop(i, 0, n)
    {
        if(visited[v[i].second - 1])
            Union(v[i].second, v[i].second - 1, v[i].first);
        if(visited[v[i].second + 1])
            Union(v[i].second, v[i].second + 1, v[i].first);
        visited[v[i].second] = true;
    }
    rloop(i, 1, n+1)
        result[i] = max(result[i], result[i + 1]);
    loop(i, 1, n+1)
    {
        cout<<result[i]<<' ';
    }
    cout<<"\n";
    return 0;
}