/*
Author: aseemraj
Problem: zgseq
*/

#include <bits/stdc++.h>
#define umap unordered_map
typedef long long ll;
using namespace std;
const int MAXN = 100005;
const int MOD = 1e9 + 7;

map<int, int> buf;
map<int, int> X;
map<int, ll> ans;

int main()
{
    int t, n, a;
    ll sum;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	buf.clear();
    	ans.clear();
    	X.clear();
    	sum = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin>>a;
    		buf[a - 1]++;
    		buf[a + 1]++;

    		X[a] = (buf[a]*ans[a] + X[a]) % MOD;
    		ans[a] = (ans[a] + 1 + X[a]) % MOD;
    		buf[a] = 0;
    	}

    	for(map<int, ll>::iterator it = ans.begin(); it != ans.end(); it++)
    		sum = (sum + it->second) % MOD;
    	cout<<sum<<"\n";
    }
    return 0;
}
