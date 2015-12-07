#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = INT_MAX;

string brand[105];
int cost[105][205];
int memo[105][205];

int main()
{
	int n, m;
	string test;
	cin>>test;
	while(test != "TheEnd")
	{
		cin>>n>>m;
		for(int i = 0; i < n; i++)
		{
			cin>>brand[i];
			for(int j = 0; j < m; j++)
			{
				cin>>cost[i][j];
			}
		}

		int dp[m][n];
		for(int j = 0; j < n; j++)
		{
			dp[0][j] = cost[j][0];
		}

		for(int i = 1; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				dp[i][j] = dp[i-1][j];
				memo[i][j] = j;
				for(int k = 0; k < n; k++)
				{
					if(dp[i-1][k] + cost[j][i] - (cost[k][i] - 100) < dp[i][j])
					{
						dp[i][j] = dp[i-1][k] + cost[j][i] - (cost[k][i] - 100);
						memo[i][j] = k;
					}
				}
				// cout<<memo[i][j]<<' ';
			}
			// cout<<"\n";
		}

		int mn = INF;
		int ans[m];
		for(int i = 0; i < n; i++)
		{
			if(dp[m-1][i] < mn)
			{
				mn = dp[m-1][i];
				ans[m-1] = i;
			}
		}
		cout<<test<<"\n";

		for(int i = m-2; i >= 0; i--)
			ans[i] = memo[i+1][ans[i+1]];
		
		int it = ans[0], i = 1, c = 1;
		vector<pair<string, int> > vans;

		while(i < m)
		{
			// cout<<ans[i]<<"\n";
			if(ans[i] == it)
				c++;
			else
			{
				vans.push_back(make_pair(brand[it], c));
				c = 1;
				it = ans[i];
			}
			i++;
		}
		vans.push_back(make_pair(brand[it], c));

		cout<<"Tk "<<mn<<"\n";
		for(vector<pair<string, int> >::iterator iter = vans.begin(); iter != vans.end(); iter++)
			cout<<iter->first<<" for "<<iter->second<<" month(s)\n";
		cout<<"\n";
		cin>>test;
	}
	cout<<test<<"\n";
	return 0;
}