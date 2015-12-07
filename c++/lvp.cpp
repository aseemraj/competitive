#include <bits/stdc++.h>
using namespace std;
 
int n, mxc, ans;
int edge1[500005];
vector<int> edge2[500005];
bool visited[500005];
int dist[500005];
int lvl[500005];
bool f;
queue<int> q;
int bfs(int node)
{
	q = queue<int>();
	q.push(node);
	lvl[node] = 0;
	int n1, n2, mxl = 0;
	while(!q.empty())
	{
		n1 = q.front();
		q.pop();
		visited[n1] = 1;
		for(vector<int>::iterator it = edge2[n1].begin(); it != edge2[n1].end(); it++)
		{
			if(!visited[*it])
			{
				q.push(*it);
				lvl[*it] = lvl[n1] + 1;
				mxl = max(mxl, lvl[*it]);
			}
		}
	}
	return mxl;
}
 
void next_city(int node, int prev, int cnt)
{
	if(visited[node])
		return;
	visited[node] = 1;
	dist[node] = cnt;
	mxc = cnt;
	if(node == n)
		f = 1;
 
	next_city(edge1[node],node,cnt+1);
	if(f)
		ans = max(ans, dist[n] - 1 + bfs(node));
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		mxc = 0;
		f = 0;
		ans = 0;
		int i;
		cin>>n;
 
		for(i=0;i<=n;i++)
		{
			edge2[i].clear();
			visited[i] = 0;
		}
		for(i=0;i<n;i++)
		{
			cin>>edge1[i];
			if(edge1[i] == -1)
				edge1[i] = n;
			edge2[edge1[i]].push_back(i);
		}
 
		dist[0] = 0;
		visited[0] = 1;
		next_city(edge1[0],0,1);
 
		if(!f)
			cout<<mxc + bfs(n) + 1<<"\n";
		else
			cout<<ans + 1<<"\n";
	}
	return 0;
}