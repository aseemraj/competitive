#include <bits/stdc++.h>
#define umap unordered_map
typedef long long ll;
using namespace std;
const int MAXN = 100005;
const int MOD = 1e9 + 7;

int main()
{
	int t, x, lvl, i;
	ll n, m, k, h1, h2;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		m = n;
		lvl = -1;
		while(m)
		{
			m >>= 1;
			lvl++;
		}
		k = n - (1LL<<lvl) + 1;
		if(x == lvl)
			cout<<k<<' ';
		else if(x < lvl)
			cout<<(1LL<<x)<<' ';
		else
			cout<<0<<' ';

		h1 = k;
		if(lvl < x)
		{
			cout<<0<<"\n";
			continue;
		}
		i = x;
		while(i--)
		{
			h1 = (h1 + 1)/2;
		}
		if(x == lvl)
			h2 = 0;
		else
			h2 = (1LL<<(lvl-x-1)) - (h1 + 1)/2;
		
		cout<<h1+h2<<"\n";
	}

	return 0;
}