#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
ll pss[1<<21];        // the power set sum array
int setbits(int i){i=i-((i>>1)&0x55555555);i=(i&0x33333333)+((i>>2)&0x33333333);return(((i+(i>>4))&0x0F0F0F0F)*0x01010101)>>24;}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, psz, c, sand, sor; ll s;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll a[n], sum;
        sum = 0;
        loop(i, 0, n)
        {
            cin>>a[i];
            sum += a[i];
        }
        if((sum==0 && k<=n) || k==1){cout<<"yes\n";continue;}
        if(sum==0 || sum%k!=0 || n<k){cout<<"no\n";continue;}
        s = sum/k;
        psz = 1<<n;         // power set size
        vector<int> subs;
        loop(i, 0, psz)
        {
            pss[i] = 0;
            loop(j, 0, n)if(i&(1<<j))pss[i]+=a[j];
            if(pss[i]==s) subs.push_back(i);
        }
        if(subs.size()<k){cout<<"no\n";continue;}
        int idx, mn = 50;
        for(vector<int>::iterator i=subs.begin();i!=subs.end();i++)
            if(setbits(*i)<mn)
                mn = setbits(*i), idx = *i;
        c = 1, sand = idx;
        for(vector<int>::iterator i=subs.begin();i!=subs.end();i++)
        {
            if(!(sand&(*i)))c++, sand = sand|(*i);
            if(c==k)break;
        }
        if(c==k)cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
