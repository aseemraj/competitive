#include<iostream>
#include<stdlib.h>
#include<string>
#include <istream>
#include <sstream>
#include <algorithm>
#include<vector>
using namespace std;
int main() {
    int t, i, j;
    string s;
    cin>>t;
    t++;
    while(t--) {
        vector<string> sarr;
        getline(cin, s);
        stringstream ss(s);
        string st;
        while(getline(ss, st, ' ')) {
            if(st!="") {
                if(find(sarr.begin(), sarr.end(), st) == sarr.end())
                    sarr.push_back(st);
            }
        }
        i = sarr.size();
        if(i!=0)
            cout<<i<<endl;
    }
    return 0;
}
