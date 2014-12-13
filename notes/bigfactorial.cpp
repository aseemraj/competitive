#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define sz 1000000
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, j, k, m;
    while(1)
    {
        cin>>n;
        if(n<0)break;
        int a[sz] = {0};
        a[0] = 1;
        m = 1;  // for saving computation
        loop(i, 2, n+1)
        {
            j=0, k=0;
            while(j<m && j<sz)
            {
                k = i*a[j]+k;
                a[j] = k%10;
                k /= 10;
                j++;
                if(k>0 && j>=m)m++;
            }
        }
        j = sz-1;
        while(a[j]==0)j--;
        cout<<endl;
        while(j>=0)cout<<a[j--];
        cout<<endl;
    }
    return 0;
}
