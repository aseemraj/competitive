/*
Author: aseemraj
Problem: DEVVOTE
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;
string vote;
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, total;
    bool valid, done;
    cin>>t;
    while(t--)
    {
        cin>>n;
        total = 0;
        int a[n+1];
        loop(i, 1, n+1)a[i]=1;
        vector<int> elems;
        while(1)
        {
            valid = 1;
            loop(j, 1, n)
            {
                if(a[j]==a[j+1])
                {
                    valid = 0;
                    break;
                }
            }
            if(valid)
            {
                // loop(i, 0, n)cout<<a[i+1];
                // cout<<endl;
                total++;
                int c = 0;
                int cnt[10] = {0};
                loop(i, 1, n+1)cnt[a[i]]++;
                int *m = max_element(cnt, cnt+10);
                loop(i, 1, n+1)
                    if(cnt[i]==(*m))
                        c++;
                elems.PB(c);
            }
            a[n]++;
            int i = n;
            while(a[i]>n && i>0)
            {
                a[i]=1, i--;
                a[i]++;
            }
            if(i<=0)break;
        }
        double sum = 0;
        loop(i, 0, elems.size())
            sum = sum + elems[i];
        double ans = sum/(double)(total);
        cout<<fixed<<setprecision(8)<<ans<<"\n";
    }
    return 0;
}
