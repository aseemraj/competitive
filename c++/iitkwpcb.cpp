#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll unsigned long long int
using namespace std;
int main()
{
    int t, n, i, k, temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool used[n+1];
        memset(used, false, sizeof used);
        int a[n];
        loop(i, 0, n)
            cin>>a[i];
        k = n;
        bool ans = true;
        if(a[0]!=0)
            ans = false;
        else
        {
            loop(i, 1, n)
                if(a[i]>i)
                {
                    ans = false;
                    break;
                }
//            rloop(i, 0, n)
//            {
//                if(a[i]>i)
//                {
//                    ans = false;
//                    break;
//                }
//                temp = k;
//                if(a[i]==0)
//                {
//                    used[k] = true;
//                    while(used[k])
//                        k--;
//                }
//                else if(used[k - a[i]])
//                {
//                    while(used[temp-a[i]])
//                        temp--;
//                    if(temp>0)
//                        used[temp-a[i]] = false;
//                    else
//                    {
//                        ans = false;
//                        break;
//                    }
//                }
//                else
//                {
//                    used[k-a[i]] = true;
//                }
//                if(!ans)
//                    break;
//            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
