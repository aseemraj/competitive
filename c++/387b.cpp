#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    int n, m;
    string s = "aseemrajb";
    cout<<s.substr(0, 3);
    cin>>n>>m;
    int a[n];
    int b[m];
    loop(i, 0, n)
        cin>>a[i];
    loop(i, 0, m)
        cin>>b[i];
    int j = 0;
    loop(i, 0, m)
    {
        if(b[i]>=a[j])
            j++;
        if(j>=n)
            break;
    }
    cout<<n-j<<endl;
    return 0;
}
