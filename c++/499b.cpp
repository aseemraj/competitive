#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    string a[m], b[m];
    map<string, string> d;
    loop(i, 0, m)
    {
        cin>>a[i]>>b[i];
        if(b[i].length()<a[i].length())d[a[i]]=b[i];
        else d[a[i]] = a[i];
    }
    string str="", s;
    loop(i, 0, n)
    {
        cin>>s;
        str += d[s] + " ";
    }
    cout<<str<<endl;
    return 0;
}
