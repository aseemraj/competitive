#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
pair<int, ll> ar[105];
vector<pair<ll, ll> >queries;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		int n;
		cin >> n;
		queries.clear();
		for(int i = 0; i < n; ++i) {
			cin >> ar[i].first >> ar[i].second;
			if(ar[i].first == 100) {
				queries.push_back(make_pair(ar[i].second, ar[i].second));
			}
			if(ar[i].first == 0) {
				continue;
			}
			ll st = (100 * ar[i].second) / ar[i].first;
			ll ed = (100 * ar[i].second) / (ar[i].first + 1);
			if(st > ed) {
				swap(st, ed);
			}
			if((100.0 * ar[i].second) / st > ar[i].first) {
				st++;
			}
			if((100.0 * ar[i].second) / ed < ar[i].first) {
				ed--;
			}
			queries.push_back(make_pair(st, ed));
		}
		ll res1 = 0, res2 = 1e18;
		int sz = queries.size();
		for(int i = 0; i < sz; ++i) {
			res1 = max(res1, queries[i].first);
			res2 = min(res2, queries[i].second);
		}
		cout << "Case #" << tcase <<": ";
		if(res1 == res2 && res1 > 0) {
			cout << res1 << endl;
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}
