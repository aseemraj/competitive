#include<iostream>
#include<vector>
using namespace std;
void radix(int ans[]);
int main() {
    int n, i, t;
    vector < vector<int> > b(10);
    cout<<"Enter the number of elements: ";
    cin>>n;
    int ans[n];
    cout<<sizeof(ans)/sizeof(*ans);
    vector <int> a(n);
    for(i=0;i<n;i++) {
        cin>>t;
        a.push_back(t);
        b[t%10].push_back(t);
    }
    cout<<sizeof(ans);
    copy(a.begin(), a.begin() + a.size(), ans);
    i = 0;
    cout<<sizeof(ans);
    while(i<sizeof(ans)) {
        cout<<ans[i]<<endl;
        i++;
    }
    //radix(ans);
//    for(i=0;i<10;i++) {
//        for(int j=0;j<b[i].size();j++)
//            cout<<b[i][j];
//    }
    return 0;
}
void radix(int x[]) {
    int i=0;
    while(i<sizeof(x)) {
        cout<<x[i]<<endl;
        i++;
    }
}
