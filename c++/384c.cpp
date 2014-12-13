#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll long long
using namespace std;

int main()
{
    long long n, res=0, cnt=0, a, i;
	cin>>n;
	loop(i, 0, n)
    {
		cin>>a;
		cnt += a;
		if(!a)res += cnt;
	}
	cout <<res<<endl;
	return 0;
}
