#include<bits/stdc++.h>
using namespace std;
char a[100005];
int b[100015];
int main()
{
	int n,k,w,i,j;
	cin>>n>>k>>w;
	scanf("%s",a+1);
	for(i=1;i<=n;i++)
	{
		b[i+k]=b[i]+=a[i]!='1';
		for(j=1;j<k;j++)
			b[i+j]+=a[i]=='1';
	}
	while(w--)
	{
		cin>>i>>j;
		cout<<b[j]-b[i-1]<<endl;
	}
	return 0;
}
