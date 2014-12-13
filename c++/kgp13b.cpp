#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define init(a, b) memset(a, b, sizeof(a))
#define all(c) c.begin(),c.end()
using namespace std;
int main()
{

    int t, ti, st, en, id, e, c, m, n, i, j, k, mx, enmx;
    cin>>t;
    loop(ti, 0, t)
    {
        cin>>e>>c;
        vector < pair < pair < int, int> , int > > det;
        enmx = 0;
        loop(i, 0, e)
        {
            cin>>st>>en;
            enmx = max(enmx, en);
            det.push_back(make_pair(make_pair(st, en), 0));
        }
        loop(i, 0, c)
        {
            cin>>k;
            loop(j, 0, k)
            {
                cin>>id;
                cin>>m;
                det[id-1].second += m;
            }
        }
        sort(all(det));
        int beds[enmx+1];
        init(beds, 0);
        mx = 0;
        loop(i, 1, enmx+1)
        {
            loop(j, 0, e)
            {
                if(i<det[j].first.first)
                    break;
                else if(i>=det[j].first.first && i<=det[j].first.second)
                    beds[i] += det[j].second;
            }
            mx = max(mx, beds[i]);
        }
        cout<<"Case "<<ti+1<<": "<<mx<<endl;
    }
    return 0;
}
