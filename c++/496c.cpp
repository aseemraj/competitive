#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    string s[n];
    loop(i, 0, n)cin>>s[i];
    bool marked[101] = {0};
    bool newmark[101];
    int cnt = 0;
    bool f;
    loop(j, 0, m)
    {
        f = 0;
        loop(i, 0, n)newmark[i]=marked[i];
        loop(i, 0, n-1)
        {
            if(marked[i])continue;
            if(s[i][j]<s[i+1][j])newmark[i]=1;
            else if(s[i][j]>s[i+1][j]){cnt++;f=1;break;}
        }
        if(f)continue;
        loop(i, 0, n)marked[i]=newmark[i];
    }
    cout<<cnt<<endl;
    return 0;
}
