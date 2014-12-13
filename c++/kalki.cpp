#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define MOD 1000000007
typedef long long ll;
using namespace std;
struct coord
{
    int x;
    int y;
};
int minkeyid(double* key, bool* mst, int n)
{
    int mi;
    double mn = 10000000000.0;
    loop(i, 1, n+1)
        if(!mst[i]&&key[i]<mn)
            mn = key[i], mi = i;
    return mi;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, x1, x2, y1, y2, idx;
    cin>>t;
    while(t--)
    {
        cin>>n;
        struct coord pos[n+1];
        // taking distances as edge weights and building a complete graph
        double dist[n+1][n+1];
        loop(i, 1, n+1)cin>>pos[i].x>>pos[i].y;
        loop(i, 1, n+1)
        {
            loop(j, 1, n+1)
            {
                x1 = pos[i].x;
                x2 = pos[j].x;
                y1 = pos[i].y;
                y2 = pos[j].y;
                dist[i][j] = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            }
        }
        bool mst[501] = {0};
        double key[n+1];
        int parent[n+1];
        loop(i, 0, n+1)key[i]=10000000000.0;
        key[1] = 0; // to be picked first
        parent[1] = -1;
        loop(i, 0, n-1)
        {
            idx = minkeyid(key, mst, n);
            mst[idx] = 1;
            loop(j, 1, n+1)
                if(i!=j && !mst[j] && dist[idx][j]<key[j])
                    parent[j] = idx, key[j] = dist[idx][j];
        }
        loop(i, 2, n+1)
            cout<<i<<' '<<parent[i]<<endl;
    }
    return 0;
}
