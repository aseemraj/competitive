#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, p, o=0, e=0;
    cin>>n>>k>>p;
    int a[n];
    vector<int> odd;
    vector<int> even;
    loop(i, 0, n)
    {
        cin>>a[i];
        if(a[i]&1)
        {
            odd.push_back(a[i]);
            o++;
        }
        else
        {
            even.push_back(a[i]);
            e++;
        }
    }
    bool ans = false;
    int szo = o;
    int sze;
    if(o>=k-p)
    {
        o -= k-p;
        if(o&1)
            cout<<"NO\n";
        else
        {
            e += o>>1;
            if(p<=e)
            {
                cout<<"YES\n";
                ans = true;
                e -= o>>1;
            }
            else
                cout<<"NO\n";
        }
    }
    else
    {
        cout<<"NO\n";
    }
    if(ans)
    {
        int counter = 0;
        int j;
        for(j=0;j<k-p;j++)
            cout<<"1 "<<odd[j]<<endl;
        counter += k-p;
        if(p<=e)
        {
            for(j=0;j<p-1;j++)
                cout<<"1 "<<even[j]<<endl;
            cout<<e+1+szo-k;
            for(;j<e;j++)
                cout<<' '<<even[j];
            for(j=k-p;j<szo;j++)
                cout<<' '<<odd[j];
            cout<<endl;
        }
        else
        {
            for(j=0;j<e;j++)
                cout<<"1 "<<even[j]<<endl;
            counter = k-p+e;
            int cnt = 0;
            for(j=k-p;j<szo;j+=2)
            {
                if(cnt==p-e-1)
                    break;
                cout<<"2 "<<odd[j]<<' '<<odd[j+1]<<endl;
                cnt++;
            }
            if(szo-j>0)
            {
                cout<<szo-j;
                for(;j<szo;j++)
                    cout<<' '<<odd[j];
                cout<<endl;
            }
        }
    }
    return 0;
}
