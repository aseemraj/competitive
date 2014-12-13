#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int b[1002][1002];
int c[1002][1002];
int main()
{
    ios::sync_with_stdio(false);
    int t, n, m, k, ans = 0, i, j, index, color;
    int mx;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>m>>k;
        int a[n];
        vector < pair < int, pair < int, int > > > indices;
        loop(i, 0, n)
            cin>>a[i];
        loop(i, 0, n)
            loop(j, 1, m+1)
                cin>>b[i][j];
        loop(i, 0, n)
            loop(j, 1, m+1)
                cin>>c[i][j];
        loop(i, 0, n)
        {
            index=-1;
            mx=0;
            loop(j, 1, m+1)
            {
                if(b[i][j]-c[i][j]-b[i][a[i]]>mx)
                {
                    mx = b[i][j]-c[i][j]-b[i][a[i]];
                    index=j;
                }
            }
            indices.push_back(make_pair(mx, make_pair(i, index)));
//            if(index==-1)
//                ans += b[i][a[i]];
//            else
//                ans += b[i][index]-c[i][index];
        }
        sort(indices.rbegin(), indices.rend());
        loop(i, 0, n)
        {
            if(k==0)
                break;
            index = indices[i].second.first;
            color = indices[i].second.second;
            if(color==-1)
                ans += b[index][a[index]];
            else
            {
                ans += b[index][color]-c[index][color];
                k--;
            }
        }
        while(i<n)
        {
            index = indices[i].second.first;
            ans += b[index][a[index]];
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
