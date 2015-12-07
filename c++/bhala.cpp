#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	cin>>n;
	int a[n];
	int sum[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(i == 0)
			sum[0] = a[0];
		else
			sum[i] = sum[i-1]+a[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		k++;
		int b = n/k;
		if(n%k == 0)
			cout<<sum[b-1]<<endl;
		else
			cout<<sum[b]<<endl;
	}
    return 0;
}
