#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
ll binsearch(ll *f, ll x, ll n)
{
    ll low = 0, high = n-1, mid;
    if(f[low]>x)return 0;
    if(f[high]<=x)return n;
    while(low<high)
    {
        mid = (low+high)/2;
        if(f[mid]<x)low=mid+1;
        else if(f[mid]>x)high=mid-1;
        else break;
    }
    mid=max(0LL, mid-2);
    while(f[mid]<=x)mid++;
    return min(n, mid);
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll n, m, mx, p2, a, b, id;
    cin>>n;
    ll f[n];
    loop(i, 0, n)cin>>f[i];
    cin>>m;
    ll s[m];
    loop(i, 0, m)cin>>s[i];
    sort(f, f+n);sort(s, s+m);
    p2 = binsearch(s, f[0]-1, m);
    a = n*3, b = p2*2 + (m-p2)*3;
    mx = a-b;
    loop(i, 0, m)
    {
        p2 = binsearch(f, s[i], n);  // number of two pointers
        id = i;
        while(s[id]==s[i])id++;
        id--;
        i = id;
        if(p2*2 + (n-p2)*3 - (i+1)*2 - (m-i-1)*3 > mx)
        {
            a = p2*2 + (n-p2)*3;
            b = (i+1)*2 + (m-i-1)*3;
            mx = a-b;
        }
        else if(p2*2 + (n-p2)*3 - (i+1)*2 - (m-i-1)*3 == mx && p2*2 + (n-p2)*3 > a)
        {
            a = p2*2 + (n-p2)*3;
            b = (i+1)*2 + (m-i-1)*3;
            mx = a-b;
        }
    }
    cout<<a<<':'<<b<<endl;
    return 0;
}
