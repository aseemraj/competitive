#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
vector<int> a;
map <int, bool> b;
int main()
{
    int n, k, t, w=0;
    cin>>n>>k;
    loop(i, 0, n)
    {
        cin>>t;
        a.push_back(t);
    }
    loop(i, 0, k)
    {
        cin>>t;
        b[t] = true;
    }
    loop(i, 0, n)
    {
        if(!b[a[i]])
        {
            int r = i;
            int s = i;
            while(a[r]>=a[i] && r>=0)
                r--;
            while(a[s]>=a[i] && s<n)
                s++;
            w += s-r-1;
            a.erase(a.begin()+i);
            i--;
            n = a.size();
        }
    }
    cout<<w<<endl;
    return 0;
}
