#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int t, cr;
    long n, i, j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==1)
            cout<<0<<endl;
        else
        {
            vector<long> arr;
            n=n/2;
            for(i=1, cr=0;i<=n/2;i++)
            {
                if(n%i==0)
                {
                    if(arr.size()!=0)
                    {
                        if(arr[cr]==i || arr[cr+1]==i)
                            break;
                    }
                    arr.insert(arr.begin() + cr, i);
                    if(i!=n/i)
                        arr.insert(arr.end() - cr, n/i);
                    cr++;
                }
            }
//            for(i=0;i<arr.size();i++)
//                cout<<arr[i]<<"\t";
//            cout<<endl;
            vector<long> ans;
            ans.push_back(1);
            for(i=1;i<arr.size();i++)
            {
                for(j=i+1;j<arr.size();j++)
                {
                    if(arr[j]%arr[i]==0)
                    {
                        ans.push_back(arr[j]);
                        arr.erase(arr.begin()+j);
                        j--;
                    }
                }
            }
            sort(ans.begin(), ans.end());
            cout<<ans.size();
            for(i=0;i<ans.size();i++)
                cout<<' '<<ans[i];
            cout<<endl;
            arr.clear();
            ans.clear();
        }
    }
    return 0;
}
