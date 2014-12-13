#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, cnt;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cnt = 0;
        n = s.size();
        bool c[200] = {0};
        loop(i, 0, n)c[s[i]]=true;
        loop(i, 97, 123)if(c[i])cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
