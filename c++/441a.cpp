#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, v, k, t;
    cin>>n>>v;
    vector<int> s[n];
    loop(i, 0, n)
    {
        cin>>k;
        loop(j, 0, k)
        {
            cin>>t;
            s[i].push_back(t);
        }
    }
    return 0;
}

