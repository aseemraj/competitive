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
ll ar[2][3005];
ll mat[3005][3005];
ll dp[3005][3005];	
int main() {
	int t;
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		ll n, k, c, x;
		cin >> n >> k >> c >> x;
		for(int i = 1; i <= n; ++i) {
			cin >> ar[0][i];
		}
		for(int i = 1; i <= n; ++i) {
			cin >> ar[1][i];
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				mat[i][j] = (ar[0][i] * i + ar[1][j] * j + c) % x;
				dp[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; ++i) {
			deque<int> d;
			for(int j = 1; j < k; ++j) {
				while((int)(d.size()) > 0 && mat[i][d.back()] < mat[i][j])
					d.pop_back();
				d.push_back(j);
			}
			for(int j = k; j <= n; ++j) {
				while((int)(d.size()) > 0 && mat[i][d.back()] < mat[i][j]) {
					d.pop_back();
				}
				d.push_back(j);
				dp[i][j] = mat[i][d.front()];
				while((int)(d.size()) > 0 && (d.front() <= (j - k + 1))) {
					d.pop_front();
				}
			}
		}
		ll res = 0;
		for(int i = k; i <= n; ++i) {
			deque<int> d;
			for(int j = 1; j < k; ++j) {
				while((int)(d.size()) > 0 && dp[d.back()][i] < dp[j][i])
					d.pop_back();
				d.push_back(j);
			}
			for(int j = k; j <= n; ++j) {
				while((int)(d.size()) > 0 && dp[d.back()][i] < dp[j][i]) {
					d.pop_back();
				}
				d.push_back(j);
				res += dp[d.front()][i];
				while((int)(d.size()) && d.front() <= (j - k + 1)) {
					d.pop_front();
				}
			}
		}
		cout << "Case #" << tcase << ": " << res << endl;
	}
	return 0;
}