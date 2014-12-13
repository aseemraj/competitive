#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
long long k,x,n,m;
vector<pair<long long, pair<long long, long long> > > vec;
vector<pair<long long, pair<long long, long long> > > ok[200];
pair<long long, pair<long long, long long> > tp;
long ai,aj;

string gener(long sz,pair<long long, pair<long long, long long> > tp)
{
 string res="";
 if (tp.second.first==1)res+="C";
 for (int i=1;i<=tp.first;i++)
 res+="AC";
 while (res.size()+1<sz)res+="B";
 if (res.size()<sz)if (tp.second.second==1)res+="A";else res+="B";
//cout<<sz<<" "<<res.size()<<endl;
 return res;
}

int main()
{
    loop(i, 1, 101)
        loop(j, 0, 101)
        {
            if (j*2+2<=i){ok[i].push_back(make_pair(j,make_pair(1,1)));}
            if (j*2+1<=i){ok[i].push_back(make_pair(j,make_pair(1,0)));}
            if (j*2+1<=i){ok[i].push_back(make_pair(j,make_pair(0,1)));}
            if (j*2<=i){ok[i].push_back(make_pair(j,make_pair(0,0)));}
        }

    cin>>k>>x>>n>>m;
    ai=aj=-1002;
    loop(i, 0, ok[n].size())
        loop(j, 0, ok[m].size())
        {
            vec.clear();
            vec.push_back(ok[n][i]);
            vec.push_back(ok[m][j]);
            for (int p=2;p<k;p++)
            {
                tp.first=vec[p-2].first+vec[p-1].first;
                tp.second.first=vec[p-2].second.first;
                tp.second.second=vec[p-1].second.second;
                if (vec[p-2].second.second==1&&vec[p-1].second.first==1)
                ++tp.first;
                if (tp.first>x)tp.first=x+2;
                vec.push_back(tp);
            }
            if (vec[k-1].first==x){ai=i;aj=j;}
        }
    if (ai+aj<0)cout<<"Happy new year!"<<endl;
    else
    {
        cout<<gener(n,ok[n][ai])<<endl;
        cout<<gener(m,ok[m][aj])<<endl;
    }
    return 0;
}
