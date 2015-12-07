/*
Author: aseemraj
Problem: kol15a
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    string s;
    cin>>t;
    while(t--)
    {
    	cin>>s;
    	int n = s.length();
    	int sum = 0;
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] >= '0' && s[i] <= '9')
    			sum += s[i] - 48;
    	}
    	cout<<sum<<"\n";
    }
    return 0;
}
