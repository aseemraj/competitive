/*
Author: aseemraj
Problem: 
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

const int MAXN = 100005;
int tree[4*MAXN];
ll A1[MAXN], A2[MAXN], ans[MAXN];

P(PI, int) query[MAXN];

VI cfr[MAXN];

int fetch(int idx, int lef, int righ, int k)
{
	if (lef == righ)
		return A1[lef];
	int mid = (lef + righ)/2;
	if (tree[2*idx+1] < k)
		return fetch(2*idx + 2, mid + 1, righ, k - tree[2*idx+1]);
	else
		return fetch(2*idx + 1, lef, mid, k);
}

void update(int idx, int lef, int righ, int x)
{
	if (lef == righ)
	{
		tree[idx]++;
		return;
	}
	else if (x <= (lef + righ)/2)
		update(2*idx + 1, lef, (lef + righ)/2, x);
	else
		update(2*idx + 2, (lef + righ)/2 + 1, righ, x);
	tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;
	cin>>n>>q;
	loop(i, 0, n)
	{
		cin >> A1[i];
		cfr[A1[i]].PB(i);
		A2[i] = A1[i];
	}
	sort(A2, A2 + n);
	loop(i, 0, q)
	{
		cin>>query[i].F.F >> query[i].F.S;
		query[i].S = i;
	}

	sort(query, query + q);
	int seeupto = n - 1;
	for(int i = q-1; i >= 0; i--)
	{
		int l = query[i].F.F;
		while(seeupto >= 0 && A2[seeupto] >= l)
		{
			while(cfr[A2[seeupto]].size())
			{
				update(0, 0, n - 1, cfr[A2[seeupto]].back());
				cfr[A2[seeupto]].pop_back();
			}
			seeupto--;
		}
		ans[query[i].S] = fetch(0, 0, n - 1, query[i].F.S);
	}
	loop(i, 0, q)
		cout<<ans[i]<<'\n';
	return 0;
}