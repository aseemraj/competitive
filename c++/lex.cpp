#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


    bool pred( pair<int,int> left, pair<int,int> right) {
        if(left.second > right.second)return true;
        if(left.first>right.first&&left.second ==right.second)return false;
        return false;
    }


int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n,m;
        cin>>n;
        cin>>m;
        int i=0;
        int arr[n];
        vector < pair <int, int> > bi;
        //int bi[m][2];
        while(i<n){
           cin>>arr[i];
           i++;
        }
        i=1;
        // bi.push_back(make_pair(0,0));
        while(i<=m){

            int a,b;
            cin>>a;
            cin>>b;
            if(b>a)
            bi.push_back(make_pair(a,b));
            else
                bi.push_back(make_pair(b,a));

            i++;
        }
        sort(bi.begin(), bi.end(), pred);
/*        for(i=0;i<m;i++){
            cout<<bi[i].first<<" "<<bi[i].second<<endl;
        }
        */
        for(i=0;i<m;i++)
        {
            int a=bi[i].first;
            int b=bi[i].second;

            if(arr[b-1]<arr[a-1]){
                int temp;
                temp=arr[a-1];
                arr[a-1]=arr[b-1];
                arr[b-1]=temp;
            }

        }
            i=0;
        while(i<n){
           cout<<arr[i]<<" ";
           i++;
        }
        cout<<endl;



    }
    return 0;
}
