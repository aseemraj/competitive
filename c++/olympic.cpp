#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, i, j, k, st, en, nump, id;
    cout<<"Test cases: ";
    cin>>t;
    while(t--)
    {
        cout<<"Number of events: ";
        cin>>k;
        vector < pair < pair <int, int> , int > > beds;
        cout<<"Start and end dates of all events: ";
        for(i=0;i<k;i++)
        {
            cin>>st>>en;
            beds.push_back(make_pair(make_pair(st, en), 0));
        }
        cout<<"Number of countries: ";
        cin>>m;
        i = 0;
        while(m>i++)
        {
            cout<<"Contry "<<i<<"- Number of events to participate in: ";
            cin>>n;
            cout<<"Event ID and Number of participants of all: ";
            for(j=0;j<n;j++)
            {
                cin>>id>>nump;
                beds[id-1].second += nump;
            }
        }
        sort(beds.begin(), beds.end());
        int maxim[k];
        for(i=0;i<k;i++)
        {
            maxim[i] = beds[i].second;
            j=i+1;
            while(beds[j].first.first<=beds[i].first.second)
                maxim[i] += beds[j].second;
        }
        m = 0;
        for(i=0;i<k;i++)
            m = max(m, maxim[i]);
        cout<<"The minimum number of beds required is: "<<m<<endl;
    }
    return 0;
}
