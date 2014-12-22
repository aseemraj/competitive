#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, l, r, a, b;
    bool mark[101] = {0};
    cin>>n>>a>>b;
    loop(i, 1, n)
    {
        cin>>l>>r;
        loop(j, l, r)mark[j]=1;
    }
    int c = 0;
    loop(i, a, b)if(!mark[i])c++;
    cout<<c<<endl;
    return 0;
}
