#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
map <int, int> ans;
int main()
{
    int n, q, k, j, m1, m2;
    cin>>n;
    int a[n];
    loop(i, 0, n)
        cin>>a[i];
    loop(i, 0, n)
    {
        m1 = 0;
        m2 = 0;
        k = a[i];
        j = i+1;
        while(a[j]>=k && j<n)
        {
            m2++;
            j++;
        }
        j = i-1;
        m1 = 1;
        while(a[j]>=k && j>=0)
        {
            if(a[j]==k)
            {
                m1 = 1;
                break;
            }
            m1++;
            j--;
        }
        ans[k] += m1*(1 + m2);
    }
    cin>>q;
    while(q--)
    {
        cin>>k;
        cout<<ans[k]<<endl;
    }
    return 0;
}
