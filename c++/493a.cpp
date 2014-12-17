#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    string h, a;
    char color, team;
    cin>>h>>a;
    int n, t, m, card[2][101] = {{0}};
    cin>>n;
    vector<pair<int, pair<int, int> > > v;
    while(n--)
    {
        cin>>t>>team>>m>>color;
        if(team=='h')team=0;
        else team=1;
        if(card[team][m]==0)
        {
            if(color=='y')card[team][m] = 1;
            else if(color=='r')
            {
                card[team][m] = 2;
                v.push_back(make_pair(t, make_pair(team, m)));
            }
        }
        else if(card[team][m]==1)
        {
            card[team][m] = 2;
            v.push_back(make_pair(t, make_pair(team, m)));
        }
    }
    sort(v.begin(), v.end());
    loop(i, 0, v.size())
    {
        if(v[i].second.first==0)cout<<h<<' ';
        else cout<<a<<' ';
        cout<<v[i].second.second<<' '<<v[i].first<<endl;
    }
    return 0;
}
