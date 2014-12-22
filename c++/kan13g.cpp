#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m, i, j, k, numnotes;
    float z;
    cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>n>>m;
        float den[n];
        for(i=0;i<n;i++)
        {
            cin>>den[i];
        }
        sort(den, den+n);
        cout<<"Case "<<k+1<<":\n";
        for(j=0;j<m;j++)
        {
            cin>>z;
            i = n-1;
            cout<<"Scenario "<<j+1<<":\n";
            while(z>0)
            {
                numnotes = int(z/den[i]);
                if(numnotes>0)
                {
                    cout<<den[i];
                    cout<<' '<<numnotes<<endl;
                }
                z = z - den[i]*int(z/den[i]);
                i--;
            }
        }
    }
    return 0;
}
