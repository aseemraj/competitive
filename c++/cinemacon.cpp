/*
Author: aseemraj
Problem: 
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 10005;
ll a[N], sum[N];
int main()
{
	int cases, t = 1, n, x, y, m;
	ll sum;
	cin>>cases;
	while(cases--)
	{
		cin>>n>>m;
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		int len = INT_MAX;
		x = y = 0;
		sum = 0;
		while(y < n)
		{
			if(sum < m)
				sum += a[y++];
			else
			{
				len = min(len, y-x);
				sum -= a[x++];
			}
		}
		while(x < n)
		{
			if(sum >= m)
			{
				len = min(len, y-x);
				sum -= a[x++];
			}
			else break;
		}
		if(len == INT_MAX) len = -1;
		cout<<"Case "<<t++<<": "<<len<<"\n";
	}
	return 0;
}