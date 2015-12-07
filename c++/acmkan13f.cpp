#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct comp
{
	bool operator()(const ll &a, const ll &b)
	{
		return a > b;
	}
};
int main()
{
	int t, n, k, num, req;
	scanf("%d",&t);
	ll ans;
	int cN = 1;
	while(t--)
	{
		ans = 0;
		scanf("%d %d",&n,&k);
		priority_queue < ll , vector< ll > , comp > pq;
		for(int i = 0;i < n; i++)
		{
			scanf("%d",&num);
			pq.push((ll)num);
		}
		//cout << "\nPQ Created\n";
		req = k - 1 - ((n - k)%(k-1));
		if(req == k-1)
			req = 0;
		//cout << "\n" 	<< req << endl;
		for(int i = 0;i <  req;i++)
			pq.push(0);
		ll sum;
		//cout << "HUFF MAN START\n";
		while(!pq.empty())
		{
			sum = 0;
			for(int i = 0;i < k;i++)
			{
				if(pq.empty())
					break;
				sum += pq.top();
				pq.pop();
			}
			//cout << sum << "\n";
			ans += sum;
			if(pq.empty())
				break;
			pq.push(sum);
		}
		printf("Case %d: %lld\n",cN,ans);
		cN++;
	}
}