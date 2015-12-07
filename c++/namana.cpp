#include <bits/stdc++.h>
using namespace std;

bool compare(long long int a, long long int b){
    return a>b;
}

bool cmp(pair<string,long long int> a,pair<string,long long int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long long int t,i,j,p,n,m,temp,ct;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>p;
        long long int pt[p];
        for(i=0;i<p;i++){
            cin>>pt[i];
        }
        cin>>n;
        vector<string> nms;
        unordered_map<string,vector<long long int> > mp;
        for(i=0;i<n;i++){
            cin>>temp;
            for(j=0;j<p;j++){
                string s;
                cin>>s;
                if(mp[s].size()==0){
                    nms.push_back(s);
                }
                mp[s].push_back(temp*pt[j]);
            }
        }
        cin>>m;
        vector<pair<string,long long int>> v;
        for(j=0;j<nms.size();j++){
            sort(mp[nms[j]].begin(),mp[nms[j]].end(),compare);
            ct=0;
            for(i=0;i<m;i++){
                ct+=mp[nms[j]][i];
            }
            pair<string,long long int> ttp;
            ttp.first=nms[j];
            ttp.second=ct;
            v.push_back(ttp);
        }
        sort(v.begin(),v.end(),cmp);
        j=0;
        for(i=0;i<v.size();i++){
            if(i==0||v[i].second!=v[i-1].second){
                j++;
            }
            cout<<j<<": "<<v[i].first<<endl;
        }
    }
    return 0;
}
