#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll unsigned long long int
using namespace std;

double adj[102][102];
int find_max(int k, int n)
{
    int imax = k; // index of the row with max pivot
    double max_pivot = abs(adj[k][k]);
    for (int i = k + 1; i < n; ++i)
    {
        double a = abs(adj[i][k]);
        if (a > max_pivot)
        {
            max_pivot = a;
            imax = i;
        }
    }
    return imax;
}

bool GaussianElimination(int n)
{
    for (int k = 0; k < n; ++k)
    {
        int imax = find_max(k, n); // finds the max pivot
        if (adj[imax][k] == 0) return true; // Singular matrix
        swap(adj[k], adj[imax]); // Swap rows k and imax
        for (int i = k + 1; i < n; ++i)
        {
            double c = adj[i][k]/adj[k][k]; // coefficient to scale row
            adj[i][k] = 0;
            for(int j=k+1;j<n;j++)
                adj[i][j] = adj[i][j] - c*adj[k][j];
        }
    }
    return false; // We have a non-singular matrix
}
int main()
{
    ios_base::sync_with_stdio(false);
	int t, i, j, n, m;
	cin>>t;
	while(t--)
    {
		cin>>n>>m;
		memset(adj, 0, sizeof adj);
		loop(i, 0, m)
        {
			int u, v;
			cin>>u>>v;
			if(u>v)
            {
                adj[u-1][v-1] = 1;
                adj[v-1][u-1] = -1;
            }
            else
            {
                adj[u-1][v-1] = -1;
                adj[v-1][u-1] = 1;
            }
		}
		bool ans = true;
		if(n&1)
			ans = false;
        else
        {
            if(GaussianElimination(n))
                ans = false;
		}
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
    }
    return 0;
}
