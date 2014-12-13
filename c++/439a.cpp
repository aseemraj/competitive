#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, d, t, songtime = 0, total, left;
    cin>>n>>d;
    loop(i, 0, n)
    {
        cin>>t;
        songtime += t;
    }
    total = songtime + 10*(n-1);
    left = d - total;
    if(left<0)
        cout<<"-1\n";
    else
        cout<<2*(n-1)+(left/5)<<endl;
    return 0;
}
