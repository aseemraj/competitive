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
map<string, vector<int> > mp;
int ar[105];
bool compare(pair<int, string> p1, pair<int, string> p2) {
	if(p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		mp.clear();
		int p;
		cin >> p;
		for(int i = 0 ; i < p; ++i) {
			cin >> ar[i];
		}
		int n;
		cin >> n;
		set<string> s;
		for(int i = 0; i < n; ++i) {
			int w;
			cin >> w;
			string str;
			for(int j = 0; j < p; ++j) {
				cin >> str;
				s.insert(str);
				mp[str].push_back(ar[j] * w);
			}
		}
		int m;
		cin >> m;
		vector<pair<int, string> >res;
		set<string>::iterator it;
		for(it = s.begin(); it != s.end(); ++it) {
			vector<int> v = mp[(*it)];
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			int cnt = 0;
			int sz = v.size();
			for(int i = 0; i < m && i < sz; ++i) {
				cnt += v[i];
			}
			res.push_back(make_pair(cnt, (*it)));
		}
		sort(res.begin(), res.end(), compare);
		cout << "Case #" << tcase << ":\n";
		int sz = res.size();
		int score = res[0].first;
		int prev_rnk = 1;
		int rnk = 1;
		for(int i = 0; i < sz; ++i) {
			if(res[i].first == score) {
				prev_rnk++;
				cout << rnk << ": " << res[i].second << endl;
			} else {
				score = res[i].first;
				// rnk++;
				rnk = prev_rnk;
				prev_rnk++;
				cout << rnk << ": " << res[i].second << endl;
			}
		}
	}
	return 0;
}
