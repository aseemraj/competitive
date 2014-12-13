#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=b-1;i>=a;i--)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long a;
    cin>>a;
    a = a%6;
    if(a==0 || a==1 || a==3)
        cout<<"yes\n";
    else
        cout<<"no\n";
	return 0;
}
