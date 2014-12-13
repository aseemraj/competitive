#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
    int t;
    unsigned long long n, m;
    cin>>t;
    while(t--) {
        cin>>n;
        m = n/2;
        if(n%2==0 && m%2==0)
            cout<<m-1;
        else if(n%2==0 && m%2==1)
            cout<<m-2;
        else if(n%2==1)
            cout<<m;
        cout<<endl;
    }
    return 0;
}
