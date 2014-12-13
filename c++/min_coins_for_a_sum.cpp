#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;

int main()
{
    int t, n, i, j, sum;
    cout<<"Number of test cases: ";
    cin>>t;
    while(t--)
    {
        cout<<"Number of coins: ";
        cin>>n;
        int v[n];
        cout<<"Values of coins: ";
        for(i=0;i<n;i++)
            cin>>v[i];
        cout<<"Sum for which minimum number is to be found: ";
        cin>>sum;
        pair < int, vector < int > > ans[sum+1];
        ans[0].first=0;
        for(i=1;i<=sum;i++)
            ans[i].first=sum*n;
        for(i=1;i<=sum;i++)
        {
            for(j=0;j<n;j++)
            {
                if(v[j]<=i and ans[i-v[j]].first+1<ans[i].first)
                {
                    ans[i].second.erase(all(ans[i].second));
                    ans[i].second.push_back(v[j]);
                    ans[i].second.insert(ans[i].second.begin()+1, all(ans[i-v[j]].second));
                    ans[i].first = ans[i-v[j]].first + 1;
                }
            }
        }
        cout<<"\nSum\tMin coins\tDenominations\n";
        for(i=0;i<=sum;i++)
        {
            if(ans[i].first!=sum+1)
            {
                cout<<i<<"\t"<<ans[i].first<<"\t\t";
                for(vector <int>::iterator it=ans[i].second.begin();it<ans[i].second.end();it++)
                    cout<<*it<<' ';
            }
            else
                cout<<i<<"\tImpossible\tImpossible";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
