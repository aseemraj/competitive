#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#define all(c) c.begin(), c.end()
#define ll long long
using namespace std;
ll n, k, pros[100002], rev[100002];
ll max1[100002], max2[100002], maxrgn;
void maxSubArraySum1(ll a[],ll siz);
void maxSubArraySum2(ll a[],ll siz);

void maxSubArraySum1(ll a[],ll siz)
{
    ll m = a[1], i;
    ll s = a[1];
    max1[1]=a[1];
    for(i=2;i<=siz;i++)
    {
        s = max(a[i], s+a[i]);
        m = max(m, s);
        max1[i] = m;
    }
    return;
}

void maxSubArraySum2(ll a[],ll siz)
{
    ll m = a[1], i;
    ll s = a[1];
    max2[1]=a[1];
    for (i=2;i<=siz;i++)
    {
        s = max(a[i], s+a[i]);
        m = max(m, s);
        max2[i] = m;
    }
    return;
}

int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=1;i<=n;i++)
		{
			cin>>pros[i];
			rev[n-i+1]=pros[i];
		}
		maxSubArraySum1(pros,n);
		maxSubArraySum2(rev,n);
		maxrgn=max1[1]+max2[n-k-1];
		for(i=2;i<n-k;i++)
			maxrgn=max(maxrgn,max1[i]+max2[n-k-i]);
		cout<<maxrgn<<endl;
	}
	return 0;
}
